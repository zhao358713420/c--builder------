//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenPictureDialog *OpenPictureDialog;
	TMainMenu *MainMenu1;
	TMenuItem *FileMenu;
	TMenuItem *OpenMenu;
	TMenuItem *ImageMenu;
	TPageControl *PageControl1;
	TPageControl *PageControl2;
	TTabSheet *LevelsPage;
	TTabSheet *CurvePage;
	TTabSheet *ImagePage;
	TImage *Image;
	TImage *LevelsImage;
	TLabel *InputMinLabel;
	TEdit *InputMinEdit;
	TLabel *InputMaxLabel;
	TEdit *InputMaxEdit;
	TLabel *OutputMinLabel;
	TEdit *OutputMinEdit;
	TLabel *OutputMaxLabel;
	TEdit *OutputMaxEdit;
	TButton *ResetButton;
	TButton *OkButton;
	TImage *CurveImage;
	TLabel *FormerLabel;
	TLabel *ArrowLabel;
	TLabel *FinalLabel;
	TButton *CurveResetButton;
	void __fastcall OpenMenuClick(TObject *Sender);
	void __fastcall DrawLevelsLine(int InputMin,int InputMax,int OutputMin,int OutputMax);
	void __fastcall ChangeLevelsImage(int InputMin,int InputMax,int OutputMin,int OutputMax);
	void __fastcall OkButtonClick(TObject *Sender);
	void __fastcall DrawCurveLine();
	int __fastcall Curve(int X);
	void __fastcall ResetButtonClick(TObject *Sender);
    void __fastcall ChangeCurveImage(TObject *Sender);
	void __fastcall CurveImageMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall CurveImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);


private:	// User declarations
	int InputMin;
	int InputMax;
	int OutputMin;
	int OutputMax;
	int i;
	int j;
	int k;
	Byte * ImageRow;
	int Height;
	int Width;
	int x;
	int y;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
