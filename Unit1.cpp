//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-6,y=-6;
int pt1=0,pt2=0;
int odbicia=0;
int prawo=0,lewo=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (Button4->Visible==true){
Timer1->Enabled=false;
Button2->Visible=false;
}

ball->Left+=x;
ball->Top+=y;

//Paletka nr 1
if (ball->Left <=p1->Left-10){
Timer1->Enabled=false;
ball->Visible=false;
pt1++;
odbicia=0;
prawo=1;
lewo=0;
Button1->Visible=true;
Button2->Visible=true;
Button3->Visible=true;
if(pt1==12 || pt2==12)
Button1->Visible=false;
}
else if( ball->Top+ball->Height > p1->Top &&
    ball->Top < p1->Top+p1->Height   &&
    ball->Left < p1->Left+p1->Width){
    if(x>0){
    x++;
    x=-x;}
    else{
    x--;
    x=-x;}
    odbicia++;
    }
//Paletka nr 2
if (ball->Left >=p2->Left+10){
Timer1->Enabled=false;
ball->Visible=false;
pt2++;
odbicia=0;
lewo=1;
prawo=0;
Button1->Visible=true;
Button2->Visible=true;
Button3->Visible=true;
if(pt1==12 || pt2==12)
Button1->Visible=false;
}
else if( ball->Top+ball->Height > p2->Top &&
    ball->Top < p2->Top+p2->Height   &&
    ball->Left > p2->Left-p2->Width){
    if(x>0){
    x++;
    x=-x;}
    else{
    x--;
    x=-x;}
                odbicia++;
                }
//lewo
//if(ball->Left<=tlo->Left)
  //     x=-x;
//gora
if(ball->Top<=tlo->Top)
    if(y>0){
    y++;
    y=-y;}
    else{
    y--;
    y=-y;}
//prawo
//if(ball->Left+ball->Width>=tlo->Width)
  //     x=-x;
//dó³
if(ball->Top+ball->Height>=tlo->Height+57)
if(y>0){
    y++;
    y=-y;}
    else{
    y--;
    y=-y;}

//Wyswietlanie punktow

AnsiString pktSt1,pktSt2,odbiciaSt;

if(pt1<10)
pktSt1="0"+IntToStr(pt1);
else
pktSt1=IntToStr(pt1);

if(pt2<10)
pktSt2="0"+IntToStr(pt2);
else
pktSt2=IntToStr(pt2);

if(odbicia<10)
odbiciaSt="0"+IntToStr(odbicia);
else
odbiciaSt=IntToStr(odbicia);

Label1->Caption=pktSt1;
Label2->Caption=pktSt2;
Label3->Caption=odbiciaSt;

if(pt1==12 || pt2==12){
Timer1->Enabled=false;
ball->Visible=false;
Button2->Visible=true;
Button1->Visible=false;
pt1=0;
pt2=0;
odbicia=0;
}











}
//---------------------------------------------------------------------------
void __fastcall TForm1::p1upTimer(TObject *Sender)
{
 if(p1->Top>63)
  p1->Top-=15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p1downTimer(TObject *Sender)
{
 if(p1->Top+p1->Height < tlo->Height+47)
 p1->Top+=15;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key==VK_UP)
     p2up->Enabled=true;
     if(Key==VK_DOWN)
     p2down->Enabled=true;
     //W for up
     if(Key==0x57)
     p1up->Enabled=true;
     //S for down
     if(Key==0x53)
     p1down->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key==VK_UP)
     p2up->Enabled=false;
     if(Key==VK_DOWN)
     p2down->Enabled=false;
     if(Key==0x57)
     p1up->Enabled=false;
     if(Key==0x53)
     p1down->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::p2downTimer(TObject *Sender)
{
 if(p2->Top+p2->Height < tlo->Height+47)
 p2->Top+=15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p2upTimer(TObject *Sender)
{
 if(p2->Top>63)
  p2->Top-=15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
ball->Left=496;
ball->Top=360;
ball->Visible=true;
if(lewo==1 && prawo==0){
x=-6;
y=-4;}
if(prawo==1 && lewo==0){
x=6;
y=-4;}
Timer1->Enabled=true;
Button1->Visible=false;
Button2->Visible=false;

Button3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
ball->Left=496;
ball->Top=360;
x=-6,y=-4;
ball->Visible=true;
Timer1->Enabled=true;
Button1->Visible=false;
Button2->Visible=false;
Button3->Visible=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Button1->Visible=false;
Button2->Visible=false;
Button3->Visible=false;
ball->Visible=false;
Timer1->Enabled=false;
Form1->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Timer1->Enabled=true;
 ball->Visible=true;
 Button1->Visible=false;
 Button2->Visible=false;
 Button4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Application->MessageBox("Witaj w grze w PingPonga! \n "
        "Sterowanie: "
        "Lewy gracz: klawisze W i S \n"
        "Prawy gracz: klawisze UP i DOWN \n"
        "Przy ka¿dej kolizji pi³eczka przyspiesza\n"
        "\n MILEJ ZABAWY \n"
        ,MB_OK);
}
//---------------------------------------------------------------------------

