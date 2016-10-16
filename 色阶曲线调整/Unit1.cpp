//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenMenuClick(TObject *Sender)
{
	if (OpenPictureDialog->Execute()) {
		Image->Picture->LoadFromFile(OpenPictureDialog->FileName);
		DrawLevelsLine(0,256,0,256);
		Height = Image->Picture->Height;
		Width = Image->Picture->Width;
		x = 0;
		y = 0;
		DrawCurveLine();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawLevelsLine(int InputMin,int InputMax,int OutputMin,int OutputMax)
{
	LevelsImage->Canvas->Pen->Color = clBlack;
	LevelsImage->Canvas->Pen->Width = 1;
	LevelsImage->Canvas->Rectangle(0,0,256,256);
	OutputMin = 255-OutputMin;
	OutputMax = 255-OutputMax;
	LevelsImage->Canvas->Pen->Color = clRed;
	LevelsImage->Canvas->Pen->Width = 2;
	LevelsImage->Canvas->MoveTo(0,OutputMin);
	LevelsImage->Canvas->LineTo(InputMin,OutputMin);
	LevelsImage->Canvas->MoveTo(InputMin,OutputMin);
	LevelsImage->Canvas->LineTo(InputMax,OutputMax);
	LevelsImage->Canvas->MoveTo(InputMax,OutputMax);
	LevelsImage->Canvas->LineTo(256,OutputMax);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawCurveLine()
{
	CurveImage->Canvas->Pen->Color = clBlack;
	CurveImage->Canvas->Pen->Width = 1;
	CurveImage->Canvas->Rectangle(0,0,255,255);
	CurveImage->Canvas->Pen->Color = clRed;
	CurveImage->Canvas->Pen->Width = 2;
	for (i = 0; i < 256; i++) {
		CurveImage->Canvas->MoveTo(i,255-Curve(i));
		CurveImage->Canvas->LineTo(i+1,255-Curve(i+1));
	}
	CurveImage->Canvas->Ellipse(x-4,255-y-4,x+4,255-y+4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChangeLevelsImage(int InputMin,int InputMax,int OutputMin,int OutputMax)
{
	for (i = 0; i < Height; i++) {
		ImageRow = (Byte *)Image->Picture->Bitmap->ScanLine[i];
		for (j = 0;j < Width; j++) {
			for (k = 0; k < 3; k++) {
				if (ImageRow[3*j+k]<InputMin) {
					ImageRow[3*j+k] = OutputMin;
				}else{
					if (ImageRow[3*j+k]>InputMax) {
						ImageRow[3*j+k] = OutputMax;
					}else{
						ImageRow[3*j+k] = OutputMin + (ImageRow[3*j+k]-InputMin)*(OutputMax - OutputMin)/(InputMax - InputMin);
					}

				}
			}
		}
	}
	Image->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OkButtonClick(TObject *Sender)
{
	InputMin = InputMinEdit->Text.ToInt();
	InputMax = InputMaxEdit->Text.ToInt();
	OutputMin = OutputMinEdit->Text.ToInt();
	OutputMax = OutputMaxEdit->Text.ToInt();
	DrawLevelsLine(InputMin,InputMax,OutputMin,OutputMax);
	ChangeLevelsImage(InputMin,InputMax,OutputMin,OutputMax);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetButtonClick(TObject *Sender)
{
	InputMinEdit->Clear();
	InputMinEdit->SetSelText("0");
	InputMaxEdit->Clear();
	InputMaxEdit->SetSelText("255");
	OutputMinEdit->Clear();
	OutputMinEdit->SetSelText("0");
	OutputMaxEdit->Clear();
	OutputMaxEdit->SetSelText("255");
	InputMin = 0;
	OutputMin = 0;
	InputMax = 255;
	OutputMax = 255;
	DrawLevelsLine(InputMin,InputMax,OutputMin,OutputMax);
	Image->Picture->LoadFromFile(OpenPictureDialog->FileName);
}
void __fastcall TForm1::ChangeCurveImage(TObject *Sender)
{
	Image->Picture->LoadFromFile(OpenPictureDialog->FileName);
    for (i = 0; i < Height; i++) {
		ImageRow = (Byte *)Image->Picture->Bitmap->ScanLine[i];
		for (j = 0;j < Width; j++) {
			for (k = 0; k < 3; k++) {
				ImageRow[3*j+k] = Curve(ImageRow[3*j+k]);
			}
		}
	}
	Image->Refresh();
}
//---------------------------------------------------------------------------

int __fastcall TForm1::Curve(int X)
{
	if (x == 0 && y == 0) {
		return X;
	}
	float Y = 0;
	Y = X*X*(float)(y-x)/(x*x-255*x) + (1-255*(float)(y-x)/(x*x-255*x))*X;
	if (Y > 255){
		Y = 255;
	}
	if (Y < 0) {
		Y = 0;
	}
    return Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CurveImageMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Y = 255-Y;
	FormerLabel->Caption = X;
	FinalLabel->Caption = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CurveImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	x = X;
	y = 255-Y;
	DrawCurveLine();
	ChangeCurveImage(this);
}
//---------------------------------------------------------------------------

