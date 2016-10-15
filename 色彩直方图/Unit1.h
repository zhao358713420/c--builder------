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
	TOpenPictureDialog *OpenPictureDialog1;
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
	TEdit *InputMin;
	TLabel *InputMaxLabel;
	TEdit *InputMax;
	TLabel *OutputMinLabel;
	TEdit *OutputMin;
	TLabel *OutputMaxLabel;
	TEdit *OutputMax;
	TButton *ResetButton;
	TButton *OkButton;
	TImage *CurveImage;
	TLabel *FormerLabel;
	TLabel *ArrowLabel;
	TLabel *FinalLabel;
	TButton *CurveResetButton;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
