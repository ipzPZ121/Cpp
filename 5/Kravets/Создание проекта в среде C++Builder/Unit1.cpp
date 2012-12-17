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
int dist;//переменная для хранения дистанции

double t;//время, как дробное число

int min;//время,минуты

int sek;//время,секунды

double v;//скорость

//получить исходные данные из полей ввода

dist=StrToInt(sEdit1->Text);

t=StrToFloat(sEdit2->Text);

// вычисление

min=floor(t); //количество минут - это целая часть числа t

sek=(min-floor(t))*100;//количество секунд - это дробная часть числа t

v=(dist/1000)/((min*60+sek)/3600);

// вывод результата

sLabel4->Caption= "Скорость: "+ FloatToStr(v)+"км/час";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sButton2Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
