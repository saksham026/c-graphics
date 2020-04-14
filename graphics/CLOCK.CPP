#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
void main()
{

int x=250,y=125,i;
int x1=250,y1=125,j;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
delay(100);
while(!kbhit())
{
for(j=270;j<=630;j=j+6)
{
for(i=270;i<=630;i=i+6)
{
  setcolor(2);
  circle(250,250,150);
  circle(250,250,140);
  line(250,250,x,y);
  line(250,250,x1,y1);
  delay(1000);
  x=250+125*cos((i*3.14)/180);
  y=250+125*sin((i*3.14)/180);
  clearviewport();
}
  setcolor(2);
  circle(250,250,150);
  circle(250,250,140);
  setcolor(4);
  line(250,250,x1,y1);
  x1=250+125*cos((j*3.14)/180);
  y1=250+125*sin((j*3.14)/180);

}
}
getch();
closegraph();
}