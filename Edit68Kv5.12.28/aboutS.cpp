//---------------------------------------------------------------------------
//   Author: Chuck Kelly,
//           Monroe County Community College
//           http://www.monroeccc.edu/ckelly
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "aboutS.h"
#include "asm.h"

//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
  AboutBox->Title->Caption = AnsiString(TITLE);
  Panel1->DoubleBuffered = true;
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormKeyPress(TObject *Sender, char &Key)
{
  static char lastKey = ' ';
  switch (toupper(Key)) {
    case 'B':
      lastKey = 'B';
      break;
    case 'M':
      if (lastKey == 'B')
        lastKey = 'M';
      else
        lastKey = ' ';
      break;
    case 'W':
      if (lastKey == 'M')
      {
        Timer1->Enabled = true;
        img->Visible = true;
        img->Top = 40;
        img->Left = -160;
      }
    default:
      lastKey = ' ';
  }
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Timer1Timer(TObject *Sender)
{
    img->Left += 10;
    if (img->Left > AboutBox->Width) {
      img->Visible = false;
      Timer1->Enabled = false;
    }
}
//---------------------------------------------------------------------------

