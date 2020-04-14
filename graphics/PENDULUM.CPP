#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void main()
{
	int gd=DETECT,gm;
	int l=100,r=20;     //length of pendulum and radius of bob
	int angle=0;
	int color=2;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	clrscr();

	setcolor(BLUE);
	line(200,100,300,100);     //base

	setcolor(RED);
	line(250,100,250,200);     //string

	setcolor(WHITE);
	circle(250,220,20);        //bob of pendulum
	setfillstyle(SOLID_FILL,GREEN); //initial color of pendulum
	floodfill(250,220,WHITE);
	delay(500);
	clrscr();

	for(angle=0;angle<=45;angle=angle+1)
	{
		setcolor(BLUE);
		line(200,100,300,100);     //base

		setcolor(RED);
		line(250,100,250+(l*sin(angle*(3.14/180))),100+(l*cos(angle*(3.14/180))));

		setcolor(WHITE);
		circle(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),20);
		setfillstyle(SOLID_FILL,color); //initial color of pendulum
		floodfill(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),WHITE);
		delay(50);
		clrscr();
		}

	color++;

	while(!kbhit())
	{
	for(angle=45;angle>=-45;angle=angle-1)
	{
		setcolor(BLUE);
		line(200,100,300,100);     //base

		setcolor(RED);
		line(250,100,250+(l*sin(angle*(3.14/180))),100+(l*cos(angle*(3.14/180))));

		setcolor(WHITE);
		circle(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),20);
		setfillstyle(SOLID_FILL,color); //initial color of pendulum
		floodfill(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),WHITE);
		delay(50);
		clrscr();
	 }
		color++;

	for(angle=-45;angle<=45;angle=angle+1)
	{
		setcolor(BLUE);
		line(200,100,300,100);     //base

		setcolor(RED);
		line(250,100,250+(l*sin(angle*(3.14/180))),100+(l*cos(angle*(3.14/180))));

		setcolor(WHITE);
		circle(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),20);
		setfillstyle(SOLID_FILL,color); //initial color of pendulum
		floodfill(250+((l+r)*sin(angle*(3.14/180))),100+((l+r)*cos(angle*(3.14/180))),WHITE);
		delay(50);
		clrscr();
	}
		color++;
	}
	getch();
	closegraph();
}
