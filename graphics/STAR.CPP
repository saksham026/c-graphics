#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\bgi");
setcolor(2);
line(100,0,150,0);
getch();
closegraph();
}