#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
float mat[2][2];
int d[8][8];
int w[8][8];
int x2[8],x3[8],y2[8],y3[8],tx,ty,g;
void dda(int x,int y,int p,int q,int c)
{
  int dx,dy,len;
  int i=1;
  float x1,y1;
  float dxi,dyi;
  dx=p-x;
  dy=q-y;

  if(abs(dx)>=abs(dy))
    len=abs(dx);
    else
    len=abs(dy);

  dxi=dx/(float)len;
  dyi=dy/(float)len;

  x1=x+(0.5*dxi);
  y1=y+(0.5*dyi);
  while(i<=len)
  {

    putpixel(x1,y1,c);
    delay(5);
    x1=x1+dxi;
    y1=y1+dyi;
    i++;

  }

}
void matrix(float a)
{
   a=a*3.14/180;
   mat[0][0]=mat[1][1]=cos(a);
   mat[0][1]=sin(a);
   mat[1][0]=-sin(a);

}
void rot1(int q[8][8])
{
  float w1;
  cout<<"enter angle for y"<<endl;
  cin>>w1;

  //int w[8][8];
  matrix(w1);
  for(int k=0;k<8;k++)
  {
    for(int j=0;j<2;j++)
    {
     w[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

  }

}
void rot(int q[8][8])
{
  float w1;
  cout<<"enter angle for x"<<endl;
  cin>>w1;

  //int f[8][8];
  matrix(w1);
  for(int k=0;k<8;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

  }

}
void main()
{

clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

int q[8][8];

int r=getmaxx();
int u=getmaxy();

dda(0,u/2,r,u/2,4);
dda(r/2,0,r/2,u,4);

int a,b,l,de,h;
cout<<"enter starting coordinates of cube"<<endl;

cin>>a>>b;

cout<<"enter lenght of side"<<endl;
cin>>l;
de=l/2;
h=l;

q[0][0]=a;
q[0][1]=b;
q[0][2]=0;

q[1][0]=a+l;
q[1][1]=b;
q[1][2]=0;

q[2][0]=a+l;
q[2][1]=b+h;
q[2][2]=0;

q[3][0]=a;
q[3][1]=b+h;
q[3][2]=0;

q[4][0]=a+de;
q[4][1]=b+de+h;
q[4][2]=2*de;

q[5][0]=a+de+l;
q[5][1]=b+de+h;
q[5][2]=2*de;

q[6][0]=a+de+l;
q[6][1]=b+de;
q[6][2]=2*de;

q[7][0]=a+de;
q[7][1]=b+de;
q[7][2]=2*de;

int i=0;

for(int j=0;j<8;j++)
{
i=i%7;
dda(q[i][0]+320,-q[i][1]+240,q[i+1][0]+320,-q[i+1][1]+240,4);
i++;

}

int p,q1;

dda(q[0][0]+320,-q[0][1]+240,q[3][0]+320,-q[3][1]+240,4);
p=(q[0][0]+q[1][0])/2+321;
q1=-(q[0][1]+q[2][1])/2+241;
setfillstyle(1,BLUE);
floodfill(p,q1,RED);

dda(q[4][0]+320,-q[4][1]+240,q[7][0]+320,-q[7][1]+240,4);
dda(q[7][0]+320,-q[7][1]+240,q[0][0]+320,-q[0][1]+240,4);
dda(q[6][0]+320,-q[6][1]+240,q[1][0]+320,-q[i][1]+240,4);
dda(q[5][0]+320,-q[5][1]+240,q[2][0]+320,-q[2][1]+240,4);

int ch,g=1;
getch();
//cleardevice();

//dda(0,u/2,r,u/2,4);
//dda(r/2,0,r/2,u,4);

cout<<"after rotation about x axis"<<endl;
rot(q);
i=0;
setcolor(9);
for(j=0;j<8;j++)
{
i=i%7;
dda(q[i][0]+320,-d[i][0]+240-2*b,q[1+i][0]+320,-d[i+1][0]+240-2*b,2);
    i++;
}
dda(q[0][0]+320,-d[0][0]+240-2*b,q[3][0]+320,-d[3][0]+240-2*b,2);

p=(q[0][0]+q[1][0])/2+320;
q1=-(d[0][0]+d[2][0])/2+240-b;
//setfillstyle(1,GREEN);
//floodfill(p,q1,2);

dda(q[4][0]+320,-d[4][0]+240-2*b,q[7][0]+320,-d[7][0]+240-2*b,2);
dda(q[7][0]+320,-d[7][0]+240-2*b,q[0][0]+320,-d[0][0]+240-2*b,2);
dda(q[6][0]+320,-d[6][0]+240-2*b,q[1][0]+320,-d[1][0]+240-2*b,2);
dda(q[5][0]+320,-d[5][0]+240-2*b,q[2][0]+320,-d[2][0]+240-2*b,2);

cout<<"after rotation about y axis"<<endl;
rot1(d);
i=0;

for(j=0;j<8;j++)
{
i=i%7;
dda(w[i][1]+320+2*a,-d[i][1]+240,w[1+i][1]+320+2*a,-d[i+1][1]+240,2);
    i++;
}
dda(w[0][1]+320+2*a,-d[0][1]+240,w[3][1]+320+2*a,-d[3][1]+240,2);

p=(w[0][0]+w[1][0])/2+320+a;
q1=-(w[0][1]+w[2][1])/2+240;
setfillstyle(1,RED);
floodfill(p,q1,2);

dda(w[4][1]+320+2*a,-d[4][1]+240,w[7][1]+320+2*a,-d[7][1]+240,2);
dda(w[7][1]+320+2*a,-d[7][1]+240,w[0][1]+320+2*a,-d[0][1]+240,2);
dda(w[6][1]+320+2*a,-d[6][1]+240,w[1][1]+320+2*a,-d[i][1]+240,2);
dda(w[5][1]+320+2*a,-d[5][1]+240,w[2][1]+320+2*a,-d[2][1]+240,2);

getch();

closegraph();

}
