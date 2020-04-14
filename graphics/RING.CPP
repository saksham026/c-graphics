#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
void main()
{
int x=375,y=250,i;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
delay(100);
for(i=0;i<=360;i=i+15)
{
setcolor(i);
circle(250,250,150);
circle(250,250,100);
  circle(x,y,20);
  delay(100);
  x=250+125*cos((i*3.14)/180);
  y=250+125*sin((i*3.14)/180);
  clearviewport();
}
getch();
closegraph();
}