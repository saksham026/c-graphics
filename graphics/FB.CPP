#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int n,i,gd,gm;
int xav=0,yav=0;
int a[20][2],ch;

void bfill(int sx,int sy,int fc,int bc)
{
  if(getpixel(sx,sy)==bc && getpixel(sx,sy)!=fc)
{

  putpixel(sx,sy,fc);
  delay(3);
  bfill(sx+1,sy,fc,bc);
  bfill(sx,sy-1,fc,bc);
  bfill(sx-1,sy,fc,bc);
  bfill(sx,sy+1,fc,bc);
  }
  return;
}

void drawp()
{
   n=4;
   a[0][0]=300;
   a[0][1]=300;
   a[1][0]=350;
   a[1][1]=300;
   a[2][0]=350;
   a[2][1]=353;
   a[3][0]=300;
   a[3][1]=353;


 for(i=0;i<4;i++)
 {
  xav+=a[i][0];
  yav+=a[i][1];

 }

 a[4][0]=a[0][0];
 a[4][1]=a[0][1];
 xav=xav/4;
 yav=yav/4;

 setcolor(1);
 for(i=0;i<4;i++)
 {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 }

 bfill(xav+1,yav+1,1,0);

 a[0][0]=325;
   a[0][1]=310;
   a[1][0]=335;
   a[1][1]=310;
   a[2][0]=325;
   a[2][1]=348;
   a[3][0]=335;
   a[3][1]=348;

   xav=0;
   yav=0;

 for(i=0;i<4;i++)
 {
  xav+=a[i][0];
  yav+=a[i][1];


 }

 a[4][0]=a[0][0];
 a[4][1]=a[0][1];
 xav=xav/4;
 yav=yav/4;

 setcolor(15);
 for(i=0;i<4;i++)
 {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 }


 bfill(xav+1,yav+1,15,1);


 a[0][0]=330;
   a[0][1]=310;
   a[1][0]=340;
   a[1][1]=310;
   a[2][0]=340;
   a[2][1]=318;
   a[3][0]=330;
   a[3][1]=318;

   xav=0;
   yav=0;

 for(i=0;i<4;i++)
 {
  xav+=a[i][0];
  yav+=a[i][1];

 }

 a[4][0]=a[0][0];
 a[4][1]=a[0][1];
 xav=xav/4;
 yav=yav/4;

 setcolor(15);
 for(i=0;i<4;i++)
 {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 }


 bfill(xav+1,yav+1,15,1);

 a[0][0]=330;
   a[0][1]=323;
   a[1][0]=340;
   a[1][1]=323;
   a[2][0]=340;
   a[2][1]=333;
   a[3][0]=330;
   a[3][1]=333;

   xav=0;
   yav=0;

 for(i=0;i<4;i++)
 {
  xav+=a[i][0];
  yav+=a[i][1];

 }

 a[4][0]=a[0][0];
 a[4][1]=a[0][1];
 xav=xav/4;
 yav=yav/4;

 setcolor(15);
 for(i=0;i<4;i++)
 {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 }


 bfill(xav+1,yav+1,15,1);

 a[0][0]=314;
   a[0][1]=323;
   a[1][0]=320;
   a[1][1]=323;
   a[2][0]=320;
   a[2][1]=333;
   a[3][0]=314;
   a[3][1]=333;

   xav=0;
   yav=0;

 for(i=0;i<4;i++)
 {
  xav+=a[i][0];
  yav+=a[i][1];

 }

 a[4][0]=a[0][0];
 a[4][1]=a[0][1];
 xav=xav/4;
 yav=yav/4;

 setcolor(15);
 for(i=0;i<4;i++)
 {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 }


 bfill(xav+1,yav+1,15,1);


}
void main()
{
clrscr();
     int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");

 drawp();
 getch();
 closegraph();
}
