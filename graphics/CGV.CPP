#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
clrscr();

setcolor(2);
line(100,100,100,180);
arc(100,120,270,90,20);             //b
arc(100,160,270,90,20);

line(140,100,160,180);             //v
line(180,100,160,180);

line(190,100,190,180);
arc(190,140,270,90,40);	       	   //d

line(240,100,240,165);
line(270,100,270,165);               //u
arc(255,165,180,360,15);

arc(330,140,90,270,40);             //c

circle(380,140,40);                  //0

line(430,100,430,180);
line(430,100,450,100);               //e
line(430,140,450,140);
line(430,180,450,180);

line(475,100,475,180);
arc(475,115,270,90,15);	       	     //p

getch();
closegraph();

}