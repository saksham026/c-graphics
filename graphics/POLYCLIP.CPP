#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

const int x_max = 160;
const int y_max = 170;
const int x_min = 40;
const int y_min = 110;

int leftclip(int t[],int v)
{
int p[16];
int x1,y1,x2,y2,k=0;

   for(int i=0;i<v;i=i+2)
   {
       if(t[i]>=x_min)
       {
	 p[k]=t[i];
	 p[k+1]=t[i+1];
	 k=k+2;

       }
       if((t[i]>x_min&&t[(i+2)%v]<x_min)||(t[i]<x_min&&t[(i+2)%v]>x_min))
       {

	  x1=t[i];
	  y1=t[i+1];
	  x2=t[(i+2)%v];
	  y2=t[((i+2)%v)+1];
	  p[k]=x_min;
	  p[k+1]= y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
	  k=k+2;

       }

   }
   for(i=0;i<k;i=i+2)
	{
	   t[i]=p[i];
	   t[i+1]=p[i+1];

	}

   return k;
}
int rightclip(int t[],int v)
{
int p[16];
int x1,y1,x2,y2,k=0;

   for(int i=0;i<v;i=i+2)
   {
       if(t[i]<=x_max)
       {
	 p[k]=t[i];
	 p[k+1]=t[i+1];
	 k=k+2;

       }
       if((t[i]>x_max&&t[(i+2)%v]<x_max)||(t[i]<x_max&&t[(i+2)%v]>x_max))
       {

	  x1=t[i];
	  y1=t[i+1];
	  x2=t[(i+2)%v];
	  y2=t[((i+2)%v)+1];
	  p[k]=x_max;
	  p[k+1]= y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
	  k=k+2;

       }

   }
   for(i=0;i<k;i=i+2)
	{
	   t[i]=p[i];
	   t[i+1]=p[i+1];

	}
   return k;

}int topclip(int t[],int v)
{
int p[16];
int x1,y1,x2,y2,k=0;

   for(int i=0;i<v;i=i+2)
   {
       if(t[i+1]>=y_min)
       {
	 p[k]=t[i];
	 p[k+1]=t[i+1];
	 k=k+2;

       }
       if((t[i+1]>y_min&&t[(i+3)%v]<y_min)||(t[i+1]<y_min&&t[(i+3)%v]>y_min))
       {

	  x1=t[i];
	  y1=t[i+1];
	  x2=t[(i+2)%v];
	  y2=t[((i+2)%v)+1];
	  p[k+1]=y_min;
	  p[k]= x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
	  k=k+2;

       }
       }

   for(i=0;i<k;i=i+2)
	{
	   t[i]=p[i];
	   t[i+1]=p[i+1];

	}

      return k;
}
int bottomclip(int t[],int v)
{
int p[16];
int x1,y1,x2,y2,k=0;

   for(int i=0;i<v;i=i+2)
   {
       if(t[i+1]<=y_max)
       {
	 p[k]=t[i];
	 p[k+1]=t[i+1];
	 k=k+2;

       }
       if((t[i+1]>y_max&&t[(i+3)%v]<y_max)||(t[i+1]<y_max&&t[(i+3)%v]>y_max))
       {

	  x1=t[i];
	  y1=t[i+1];
	  x2=t[(i+2)%v];
	  y2=t[((i+2)%v)+1];
	  p[k+1]=y_max;
	  p[k]= x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
	  k=k+2;

       }

   }
   for(i=0;i<k;i=i+2)
	{
	   t[i]=p[i];
	   t[i+1]=p[i+1];

	}

	return k;
}
void main()
{

clrscr();
int gd = DETECT, gm;
    initgraph (&gd, &gm, "c:\\turboc3\\bgi");
    cleardevice();
    //int t[8]={80,80,130,80,130,140,80,140};
    int t[8]={30,140,110,100,170,140,180,140};

    setcolor(4);
    line(40,110,160,110);
    line(160,110,160,170);
    line(160,170,40,170);
    line(40,170,40,110);

setfillstyle(1,RED);
fillpoly(4,t);

int v=8;
    getch();
    setcolor(2);
   v=leftclip(t,v);
   getch();

   v=rightclip(t,v);
   getch();

   v=bottomclip(t,v);
    v=topclip(t,v);

setfillstyle(1,GREEN);

fillpoly((v/2),t);

    cout<<"window color is red ,original line is white ,clipped line is green";


    getch();
    closegraph();
}
