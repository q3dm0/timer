//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
short h, m, s;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Form1->Hide();
ShowWindow(Handle,SW_HIDE); // �������� ���������
ShowWindow(Application->Handle,SW_HIDE); // �������� ������ � TaskBar$$�
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  h = StrToInt( SpinEdit1 -> Text );
  m = StrToInt( SpinEdit2 -> Text );
  s = StrToInt( SpinEdit3 -> Text );
  Timer1 -> Enabled = true;


//WinExec("shutdown -s -t 0", SW_HIDE); // ����������
//WinExec("shutdown -r -t 0", SW_HIDE); // ������������
//WinExec("shutdown -l -t 0", SW_HIDE); // �����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if ( s >= 1 ) 
{s--;}
else if ( s <= 0 ) 
{s = 59; s--;
if ( m >= 1 ) 
{m--;}
else if ( m <= 0 )
{m = 59;
if ( h >= 1 ) 
{h--;}
else if ( s <= 0, m <= 0, h <= 0 ) 
{
WinExec("shutdown -s -t 0", SW_HIDE);
}}
if (m<1) {
Form2->Show();
Form1->Hide();
}}

Form2->Label1->Caption = IntToStr(s);
SpinEdit1->Text = IntToStr(h);
SpinEdit2->Text = IntToStr(m);
SpinEdit3->Text = IntToStr(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
Form1->Visible = true;
Application->Restore();
Form1->FormStyle = fsStayOnTop;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Minimize(TObject *Sender)
{
Application->Minimize();
Form1->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form1->Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

