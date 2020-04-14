#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int speed;int no;int amount=200;int net=200;int bet=0;
int q=0;int q1=0;

void draw_circle()
{
	setcolor(WHITE);
	int x=300,y=100;
	int x1,y1;
	int ang=30;
	int color;
	int der=40;
	for(int j=1;j<=speed;j=j+10)
	{

		delay(der);
		clearviewport();
		int ar[]={470,240,520,220,500,240,520,260};
		setfillstyle(1,RED);
		fillpoly(4,ar);

		q=q+ang;
		for(int k=1;k<=8;k++)
		{
			circle(300,250,150);
			q=q+45;
			x=300+150*cos(-q*3.14/180);
			y=250+150*sin(-q*3.14/180);
			line(300,250,x,y);
		}

		q1=q1+20;
		color=1;
		int index=0;
		const char *num[]={"1","2","3","4","5","6","7","8"};
		for(int m=1;m<=8;m++)
		{
			q1+=45;
			x1=300+110*cos(q1*3.14/180);
			y1=250+110*sin(q1*3.14/180);
			setfillstyle(SOLID_FILL,color);
			floodfill(x1,y1,WHITE);
			outtextxy(x1,y1,num[index]);
			color++;
			index++;
		}
		der=der+speed;
	}

}

void check()
{
	int color=getpixel(440,240);
	printf("\nChosen no.=%d",no);
	printf("color %d",color);
	if(color==no)
	{
		printf("\nYou have won!!!!");
		net=net+(0.5*bet);
		printf("\nBalance=%d $",net);
	}
	else
	{
		printf("\lost");
		net=net-bet;
		printf("\nBalance=%d $",net);
		if(net<50)
		{
			printf("\nYOU DO NOT HAVE SUFFICIENT BALANCE");
			getch();
			exit(0);
		}
	}
}

void main()
{
	int gd=DETECT,gm;int ch;
	clrscr();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	int size=6;
	while(!kbhit())
	{
	for(size=6;size<=8;size++)
	{
	clearviewport();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,size);
	outtextxy(60,170,"Wheel of Doom");

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(170,290,"TEST OF THE BEST AGAINST THE REST");
	outtextxy(170,370,"--Press Enter to start Game--");
	delay(800);
	if(kbhit())
		break;
	}

	for(size=8;size>=6;size--)
	{
	clearviewport();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,size);
	outtextxy(60,170,"Wheel of Doom");

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(170,290,"TEST OF THE BEST AGAINST THE REST");
	outtextxy(170,370,"--Press Enter to start Game--");
	delay(800);
	if(kbhit())
		break;
	}
	}

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	getch();
	clrscr();
	while(ch!=0)
	{
		clearviewport();
		srand(time(NULL));
		printf("Enter the Speed of the wheel between 50 & 300: ");
		scanf("%d",&speed);
		speed+=12*(1+random(13));
		printf("\nEnter a number from 1 to 8 to place your bet on : ");
		scanf("%d",&no);
		if(no>=1 && no<=8)
		{
		printf("\nInitial Balance : 200 $");
		printf("\nEnter the betting amount not less than 50 : ");
		scanf("%d",&bet);
		if(bet>net || bet <50)
		{
			printf("enter right amount to bet");
			getch();
			ch=0;
		}
		else
		{
			clrscr();

			draw_circle();
			check();
			getch();

			printf("\nEnter 0 to exit the game");
			scanf("%d",&ch);
		}
		}

		else
		{
			printf("\nSahi no. daalo");
		}
	}
	closegraph();
}
