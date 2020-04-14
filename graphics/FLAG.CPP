#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void bezier(int x[4], int y[4])
{
    int i;
    double t;
    for(t=0;t<1.0;t+=0.003)
    {
	double xt = (pow (1-t, 3) * x[0]) + (3 * t * pow (1-t, 2) * x[1]) +
		    (3 * pow (t, 2) * (1-t) * x[2]) + pow (t, 3) * x[3];

	double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
		    3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];

	       //	    delay(4);
	putpixel (xt, yt, BLUE);
    }


    return;
}

void main()
{
    int x[4], y[4];
    int x1[4], y1[4];

    int i;
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");

/*   printf ("Enter the x and y co-ordinates of the four control points.\n");
    for (i=0; i<4; i++)
	cin>>x[i]>>y[i];
  */
  x[0]=220;
  y[0]=120;

  x[1]=250;
  y[1]=160;

  x[2]=280;
  y[2]=80;

  x[3]=320;
  y[3]=120;

  x1[0]=220;
  y1[0]=190;

  x1[1]=250;
  y1[1]=230;

  x1[2]=280;
  y1[2]=150;

  x1[3]=320;
  y1[3]=190;
    int t;
  while(1)
  {
  t=x[2];
  x[2]=x[1];
  x[1]=t;

  t=y[2];
  y[2]=y[1];
  y[1]=t;

  t=y1[2];
  y1[2]=y1[1];
  y1[1]=t;

  t=x1[2];
  x1[2]=x1[1];
  x1[1]=t;

  bezier (x, y);
  bezier (x1, y1);

  setcolor(15);
  line(220,115,220,300);

  setcolor(1);
  line(320,120,320,190);
  delay(100);
  cleardevice();

  }
  line(220,115,220,300);

  setcolor(1);
  line(320,120,320,190);

  getch();
  closegraph();

}