//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sButton"
#pragma link "sEdit"
#pragma link "sLabel"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sButton1Click(TObject *Sender)
{
int dist;//���������� ��� �������� ���������

double t;//�����, ��� ������� �����

int min;//�����,������

int sek;//�����,�������

double v;//��������

//�������� �������� ������ �� ����� �����

dist=StrToInt(sEdit1->Text);

t=StrToFloat(sEdit2->Text);

// ����������

min=floor(t); //���������� ����� - ��� ����� ����� ����� t

sek=(min-floor(t))*100;//���������� ������ - ��� ������� ����� ����� t

v=(dist/1000)/((min*60+sek)/3600);

// ����� ����������

sLabel4->Caption= "��������: "+ FloatToStr(v)+"��/���";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sButton2Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
