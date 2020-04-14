#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

void midPoint(int x_centre, int y_centre, int r,int W)
{
    int x = r, y = 0;

    putpixel(x + x_centre, y + y_centre,W);

      putpixel(x + x_centre, -y + y_centre,W);
      putpixel(y + x_centre, x + y_centre,W);
      putpixel(-y + x_centre, x + y_centre,W);

    int P = 1 - r;       //initial value as point is r,0 for center 0,0
    while ( y<=x)
    {
	y++;

	delay(25);
	if (P <= 0)
	    P = P + 2*y + 1;

	else
	{
	    x--;
	    P = P + 2*y - 2*x + 1;
	}

	if (x < y)
	    break;

	putpixel(x + x_centre, y + y_centre,W);
      putpixel(-x + x_centre, y + y_centre,W);
      putpixel(x + x_centre, -y + y_centre,W);
      putpixel(-x + x_centre, -y + y_centre,W);

	if (x != y)        //FOR symmetry between x and y axis
	{

	    putpixel(y + x_centre, x + y_centre,W);
      putpixel(-y + x_centre, x + y_centre,W);
      putpixel(y + x_centre, -x + y_centre,W);
      putpixel(-y + x_centre, -x + y_centre,W);


	}


    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    midPoint(80, 70, 30,1);
    midPoint(155, 70, 30,6);
    midPoint(245, 70, 30,4);
    midPoint(125, 100, 30,14);
    midPoint(205, 100, 30,2);

    getch();

    closegraph();
}
