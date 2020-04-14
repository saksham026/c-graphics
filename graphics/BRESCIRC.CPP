#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>

void drawCircle(int xc, int yc, int x, int y,int c)
{
    putpixel(xc+x, yc+y, c);
    putpixel(xc-x, yc+y, c);
    putpixel(xc+x, yc-y, c);
    putpixel(xc-x, yc-y, c);
    putpixel(xc+y, yc+x, c);
    putpixel(xc-y, yc+x, c);
    putpixel(xc+y, yc-x, c);
    putpixel(xc-y, yc-x, c);
}

void circleBres(int xc, int yc, int r,int c)
{
    int x=0,y=r;
    int d=3-2*r;
    while (y >= x)
    {
	drawCircle(xc, yc, x, y,c);
	x++;

	if (d > 0)
	{
	    y--;
	    d = d + 4 * (x - y) + 10;
	}
	else
	    d = d + 4 * x + 6;
	drawCircle(xc, yc, x, y,c);
	delay(40);
    }
}

void main()
{
    int xc = 70, yc = 70, r= 40;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    //setbkcolor(9);
    circleBres(xc, yc, r,1);
    circleBres(160, yc, r,6);
    circleBres(250, yc, r,4);
    circleBres(130, 120, r,14);
    circleBres(195, 120, r,2);


    getch();                        //1 0 4 14 2
    closegraph();
}