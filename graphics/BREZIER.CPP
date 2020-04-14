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

		    delay(4);
	putpixel (xt, yt, BLUE);
    }

	setcolor(RED);
    for (i=0; i<3; i++)
	line(x[i], y[i],x[i+1],y[i+1]);

    return;
}

void main()
{
    int x[4], y[4];
    int x1[4], y1[4];

    int i;
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");

/*    printf ("Enter the x and y co-ordinates of the four control points.\n");
    for (i=0; i<4; i++)
	cin>>x[i]>>y[i];
  */
  x[0]=95;
  y[0]=105;

  x[1]=200;
  y[1]=100;

  x[2]=200;
  y[2]=200;

  x[3]=100;
  y[3]=200;

  x1[0]=100;
  y1[0]=200;

  x1[1]=200;
  y1[1]=200;

  x1[2]=200;
  y1[2]=300;

  x1[3]=95;
  y1[3]=295;

  bezier (x, y);
  bezier (x1, y1);

    getch();
    closegraph();

}