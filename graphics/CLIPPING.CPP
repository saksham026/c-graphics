#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
const int in = 0; // 0000
const int left = 1;   // 0001
const int right = 2;  // 0010
const int bottom = 4; // 0100
const int top = 8;    // 1000

const int xmax = 160;
const int ymax = 170;
const int xmin = 40;
const int ymin = 110;

int compute(double x, double y)
{
	int code = in;

    if (x < xmin)       // to the left of rectangle
	code |= left;
    else if (x > xmax)  // to the right of rectangle      //**abrl
	code |= right;
    if (y < ymin)       // below the rectangle
	code |= top;
    else if (y > ymax)  // above the rectangle
	code |= bottom;

    return code;
}

void cohenSutherlandClip(double x1, double y1,
			 double x2, double y2)
{
    int code1 = compute(x1, y1);
    int code2 = compute(x2, y2);

    int accept=0;

    while (1)
    {
	if ((code1 == 0) && (code2 == 0))
	{
	    accept =1;
	    break;
	}
	else if (code1 & code2)
	{
	    break;
	}
	else
	{
	    int out;
	    double x, y;

	    if (code1 != 0)
		out = code1;
	    else
		out = code2;

	    if (out & bottom)
	    {
		x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
		y = ymax;
	    }
	    else if (out & top)
	    {
			x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
		y = ymin;
	    }
	    else if (out & right)
	    {
		y = y + (y2 - y1) * (xmax - x1) / (x2 - x1);
		x = xmax;
	    }
	    else if (out & left)
	    {
		y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
		x = xmin;
	    }

	    if (out == code1)
	    {
		x1 = x;
		y1 = y;
		code1 = compute(x1, y1);
	    }
	    else
	    {
		x2 = x;
		y2 = y;
		code2 = compute(x2, y2);
	    }
	}
    }
    if (accept)
    {
	cout <<"Line accepted from " << x1 << ", "
	     << y1 << " to "<< x2 << ", " << y2 << endl;

	     delay(50);
	     line(x1,y1,x2,y2);
	}

    else
       cout << "Line rejected" << endl;
}
void main()
{

clrscr();
int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");
    cleardevice();

    line(100,100,160,160);
    line(160,160,40,160);
    line(40,160,100,100);

    setcolor(4);
    line(40,110,160,110);
    line(160,110,160,170);
    line(160,170,40,170);
    line(40,170,40,110);


    setcolor(2);
    getch();
    cohenSutherlandClip(100, 100, 160, 160);

    cohenSutherlandClip(160, 160, 40, 160);

    cohenSutherlandClip(40, 160, 100, 100);

    cout<<"window color is red ,original line is white ,clipped line is green";


    getch();
    closegraph();
}
