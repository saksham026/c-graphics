#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
int sign (float arg)
{
    if(arg>0)
    {
      return 1;
    }
    else
      return -1;
}

void bresen(int x0, int y0, int x1, int y1)
{
    int s1,s2,ex,y,x,i;
    float dx,dy,g,temp;

     dx = abs(x1 - x0);
     dy = abs(y1 - y0);

     x=x0;
     y=y0;

     s1=sign(x1-x0);
     s2=sign(y1-y0);

    if(dy>dx)
    {
    temp=dx;
    dx=dy;
    dy=temp;
    ex=1;
    }
    else
    ex=0;

    g=2*dy-dx;
    i=1;
    while(i<=dx)
    {
      putpixel(x,y,RED);
      delay(10);
      if(g>=0)
      {
	 if(ex==1)
	 x=x+s1;
	 else
	 y=y+s2;

	 g=g+2*dy-2*dx;
     }
     else
     {
	g=g+2*dy;
     }
     if(ex==1)
	 y=y+s2;
	 else
	 x=x+s1;


	 i++;
     }
}
int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");
    cleardevice();
    int X0 = 2, Y0 = 2, X1 = 2, Y1 = 130;
    bresen(2, 2, 2, 130);
    getch();
    closegraph();
    return 0;
}