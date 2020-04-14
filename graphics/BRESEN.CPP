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

void b(int x0, int y0, int x1, int y1,int co)
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
      putpixel(x,y,co);
	     delay(10);
      if(g>=0)
      {
	 if(ex==1)
	 x=x+s1;
	 else
	 y=y+s2;

	 g=g-2*dx;
     }
     if(ex==1)
	 y=y+s2;
	 else
	 x=x+s1;

	 g=g+2*dy;
	 i++;
     }


}
void main()
{
    int gd = DETECT, gm;
    int X0,Y0;

    initgraph (&gd, &gm, "c:\\turboc3\\bgi");
    printf("enter the translating factor of c and d");
    scanf("%d %d",&X0,&Y0);

    setcolor(RED);
    cout<<"before translation"<<endl;
    b(100, 100, 150, 100,2);
    b(150, 100, 125, 150,2);
    b(125, 150, 100, 100,2 );

    b(125, 80, 100, 130,2);

    b(100, 130, 150, 130,2);
    b(150, 130, 125, 80,2);

    getch();
    closegraph();

}
