#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

int Dx,Dy,i,length;
float dx,dy,x,y;

void dda(int x0,int y0,int x1,int y1)
{
	Dx=x1-x0;
	Dy=y1-y0;

	if(abs(Dx)>abs(Dy))
		length=abs(Dx);
	else
		length=abs(Dy);

	dx=Dx/(float)length;
	dy=Dy/(float)length;

	x=(float)x0+(0.5*dx);
	y=(float)y0+(0.5*dy);
	putpixel(floor(x),floor(y),2);

	for(i=1;i<=length;i++)
	{
		x=x+dx;
		y=y+dy;
		putpixel(floor(x),floor(y),2);
		delay(1);
	}
}

void main()
{
int x1,y1,x2,y2,x3,y3,x4,y4,tx,ty,sx,sy,shx=1,ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	clrscr();

	int r=getmaxx();
int u=getmaxy();
cleardevice();

dda(0,u/2,r,u/2);
dda(r/2,0,r/2,u);

	printf("Enter All Coordinates");
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

	dda(x1+320,-y1+240,x2+320,-y2+240);
	dda(x2+320,-y2+240,x3+320,-y3+240);       //rectangle
	dda(x3+320,-y3+240,x4+320,-y4+240);
	dda(x4+320,-y4+240,x1+320,-y1+240);

	int a=1;
	float th;
	while(a!=0)
	{
	printf("Enter Your Choice 1.Translation 2.Scaling 3.SHEARING");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	printf("Enter Translation Factor Tx and Ty");
	scanf("%d%d",&tx,&ty);
	dda((x1+tx+320),(-y1-ty+240),(x2+tx+320),(-y2-ty+240));
	dda((x2+tx+320),(-y2-ty+240),(x3+tx+320),(-y3-ty+240));
	dda((x3+tx+320),(-y3-ty+240),(x4+tx+320),(-y4-ty+240));
	dda((x4+tx+320),(-y4-ty+240),(x1+tx+320),(-y1-ty+240));
	break;
	case 2:
	printf("Enter Scaling Factor Sx and Sy");
	scanf("%d%d",&sx,&sy);
	dda((x1*sx)+320,(-y1*sy+240),(x2*sx)+320,(-y2*sy+240));
	dda((x2*sx)+320,(-y2*sy+240),(x3*sx)+320,(-y3*sy+240));
	dda((x3*sx)+320,(-y3*sy+240),(x4*sx)+320,(-y4*sy+240));
	dda((x4*sx)+320,(-y4*sy+240),(x1*sx)+320,(-y1*sy+240));
	break;
	case 3:

	printf("R after SHEARING");
	dda(x1+320,-y1+240,x2+shx*y2+320,-y2+240);
	dda(x1+320,-y1+240,x4+320,-y4+240);       //rectangle
	dda(x2+shx*y2+320,-y2+240,x3+shx*y3+320,-y3+240);
	dda(x3+shx*y3+320,-y3+240,x4+320,-y4+240);
	getch();

	break;
	case 4:
	printf("Enter rotating angle");
	scanf("%f",&th);
	th=th*(3.14/180);

	printf("%f",sin(th));
	int p1,p2,q1,q2,r1,r2,s1,s2;

	p1=(x1*cos(th)-y1*sin(th));
	p2=(x1*sin(th)+y1*cos(th));
	q1=(x2*cos(th)-y2*sin(th)) ;
	q2=(x2*sin(th)+y2*cos(th)) ;
	r1=(x3*cos(th)-y3*sin(th)) ;
	r2=(x3*sin(th)+y3*cos(th)) ;
	s1=(x4*cos(th)-y4*sin(th)) ;
	s2=(x4*sin(th)+y4*cos(th)) ;


	dda(p1+320,-p2+240,q1+320,-q2+240);
	dda(q1+320,-q2+240,r1+320,-r2+240);
	dda(r1+320,-r2+240,s1+320,-s2+240);
	dda(s1+320,-s2+240,p1+320,-p2+240);

	break;

	case 5:
	printf("reflection about xy axis");

	 dda((y1+320),(-x1+240),(y2+320),(-x2)+240);
	 dda((y2+320),(-x2+240),(y3+320),(-x3)+240);
	 dda((y3+320),(-x3+240),(y4+320),(-x4)+240);
	 dda((y4+320),(-x4+240),(y1+320),(-x1)+240);
       break;

	case 6:
	a=0;

	break;
	default:
	printf("wrong choice");
	}

	}

	getch();
	closegraph();
}

