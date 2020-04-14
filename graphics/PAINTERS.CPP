#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
int d[4],z[4];
int depth()
{
int t;

  for(int i=1;i<4;i++)
 {
  for(int q=1;q<3;q++)
 {
    if(d[q]<d[q+1])
    {
      t=d[q];
      d[q]=d[q+1];
      d[q+1]=t;
      t=z[q];
      z[q]=z[q+1];
      z[q+1]=t;

    }
 }
 }

 return z[1];
}

void main()
{
    int x = 70, y = 70, l= 40,b=30;
    int x1=50,y1=90,s=40;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    int t[6]={70,70,110,110,30,110};

    int ch;
    cout<<"enter depth of each"<<endl;
    cout<<"rectangle:";
    cin>>d[1];
    z[1]=1;
    cout<<"square:";
    cin>>d[2];
    z[2]=2;
    cout<<"triangle:";
    cin>>d[3];
    z[3]=3;

   for(int i=0;i<3;i++)
    {
    //cin>>ch;
     ch=depth();
	d[1]=0;
    switch(ch)
    {

    case 1:
     setcolor(BLUE);
    rectangle(x,y,x+l,y+b);
    setfillstyle(1,YELLOW);

    floodfill(80,80,BLUE);

    break;
    case 2:

    setcolor(GREEN);
    rectangle(x1,y1,x1+s,y1+s);
     setfillstyle(1,CYAN);

     floodfill(60,100,GREEN);
    break;
    case 3:
    setfillstyle(1,RED);
    fillpoly(3,t);
    break;
    default:
    cout<<"it's over"<<endl;
    break;

    }
    }
    getch();
    closegraph();

}