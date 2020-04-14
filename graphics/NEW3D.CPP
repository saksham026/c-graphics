#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
int de;
float mat[3][3];
int d[8][8];
int w[8][8];
int x2[8],x3[8],y2[8],y3[8],tx,ty,g;
void dda(float x,float y,float p,float q,int c)
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
void matrix1(float a)
{

   mat[1][2]=0;
   mat[2][1]=0;

   a=a*3.14/180;
   mat[1][1]=1;
   mat[0][0]=mat[2][2]=cos(a);
   mat[0][2]=sin(a);
   mat[2][0]=-sin(a);

}
void matrix(float a)
{
   a=a*3.14/180;
   mat[0][0]=1;
   mat[2][2]=mat[1][1]=cos(a);
   mat[1][2]=-sin(a);
   mat[2][1]=sin(a);

}
void rot1(int q[8][8])
{
  float w1;
  cout<<"enter angle for y"<<endl;
  cin>>w1;

  //int w[8][8];
  matrix1(w1);
  for(int k=0;k<8;k++)
  {
    for(int j=0;j<3;j++)
    {
     w[k][j]=d[k][0]*mat[0][j]+d[k][1]*mat[1][j]+d[k][2]*mat[2][j];

     }

  }
  cout<<"aaaaaaaa";

}
void rot(int q[8][8])
{
  float w1;
  cout<<"enter angle for x"<<endl;
  cin>>w1;
    // de=cos(w1*3.14/180)*de;
  //int f[8][8];
  matrix(w1);
  for(int k=0;k<8;k++)
  {
    for(int j=0;j<3;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j]+q[k][2]*mat[2][j];

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

int a,b,l,h;
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

q[4][0]=a;
q[4][1]=b+h;
q[4][2]=2*de;

q[5][0]=a+l;
q[5][1]=b+h;
q[5][2]=2*de;

q[6][0]=a+l;
q[6][1]=b;
q[6][2]=2*de;

q[7][0]=a;
q[7][1]=b;
q[7][2]=2*de;
int i=0;

dda(q[0][0]+320,-q[0][1]+240,q[1][0]+320,-q[1][1]+240,4);
dda(q[1][0]+320,-q[1][1]+240,q[2][0]+320,-q[2][1]+240,4);
dda(q[2][0]+320,-q[2][1]+240,q[3][0]+320,-q[3][1]+240,4);
dda(q[3][0]+320,-q[3][1]+240,q[4][0]+320,-q[4][1]+240,4);
dda(q[4][0]+320,-q[4][1]+240,q[5][0]+320,-q[5][1]+240,4);
dda(q[5][0]+320,-q[5][1]+240,q[6][0]+320,-q[6][1]+240,4);
dda(q[6][0]+320,-q[6][1]+240,q[7][0]+320,-q[7][1]+240,4);

int p,q1;
dda(q[0][0]+320,-q[0][1]+240,q[3][0]+320,-q[3][1]+240,4);

p=(q[0][0]+q[1][0])/2+321;
q1=-(q[0][1]+q[2][1])/2+241;
setfillstyle(1,BLUE);
floodfill(p,q1,RED);

dda(q[4][0]+320,-q[4][1]+240,q[7][0]+320,-q[7][1]+240,4);
dda(q[7][0]+320,-q[7][1]+240,q[0][0]+320,-q[0][1]+240,4);

delay(1000);
dda(q[6][0]+320,-q[6][1]+240,q[1][0]+320,-q[1][1]+240,4);
delay(100);
dda(q[5][0]+320,-q[5][1]+240,q[2][0]+320,-q[2][1]+240,4);

int ch,g=1;
getch();
cleardevice();

//dda(0,u/2,r,u/2,4);
//dda(r/2,0,r/2,u,4);

cout<<"after rotation about x axis"<<endl;
rot(q);
i=0;
setcolor(9);

dda(d[0][0]+320,-d[0][1]+240,d[1][0]+320,-d[1][1]+240,9);
dda(d[1][0]+320,-d[1][1]+240,d[2][0]+320,-d[2][1]+240,9);
dda(d[2][0]+320,-d[2][1]+240,d[3][0]+320,-d[3][1]+240,9);
dda(d[3][0]+320,-d[3][1]+240,d[4][0]+320,-d[4][1]+240,9);
dda(d[4][0]+320,-d[4][1]+240,d[5][0]+320,-d[5][1]+240,9);
dda(d[5][0]+320,-d[5][1]+240,d[6][0]+320,-d[6][1]+240,9);
dda(d[6][0]+320,-d[6][1]+240,d[7][0]+320,-d[7][1]+240,9);

//int p,q1;
dda(d[0][0]+320,-d[0][1]+240,d[3][0]+320,-d[3][1]+240,9);

p=(d[0][0]+d[1][0])/2+321;
q1=-(d[0][1]+d[2][1])/2+241;
//setfillstyle(1,BLUE);
//floodfill(p,q1,RED);

dda(d[4][0]+320,-d[4][1]+240,d[7][0]+320,-d[7][1]+240,9);
dda(d[7][0]+320,-d[7][1]+240,d[0][0]+320,-d[0][1]+240,9);
dda(d[6][0]+320,-d[6][1]+240,d[1][0]+320,-d[1][1]+240,9);
dda(d[5][0]+320,-d[5][1]+240,d[2][0]+320,-d[2][1]+240,9);

cout<<"after rotation about y axis"<<endl;
rot1(d);
i=0;
setcolor(2);
cout<<"bbbbbbbbbbbbbb"<<endl;

line(w[0][0]+320,-w[0][1]+240,w[1][0]+320,-w[1][1]+240);
line(w[1][0]+320,-w[1][1]+240,w[2][0]+320,-w[2][1]+240);
line(w[2][0]+320,-w[2][1]+240,w[3][0]+320,-w[3][1]+240);
line(w[3][0]+320,-w[3][1]+240,w[4][0]+320,-w[4][1]+240);
line(w[4][0]+320,-w[4][1]+240,w[5][0]+320,-w[5][1]+240);
line(w[5][0]+320,-w[5][1]+240,w[6][0]+320,-w[6][1]+240);
line(w[6][0]+320,-w[6][1]+240,w[7][0]+320,-w[7][1]+240);

//int p,q1;
line(w[0][0]+320,-w[0][1]+240,w[3][0]+320,-w[3][1]+240);

p=(w[0][0]+w[1][0])/2+321;
q1=-(w[0][1]+w[2][1])/2+241;
//setfillstyle(1,BLUE);
//floodfill(p,q1,RED);

line(w[4][0]+320,-w[4][1]+240,w[7][0]+320,-w[7][1]+240);
line(w[7][0]+320,-w[7][1]+240,w[0][0]+320,-w[0][1]+240);
line(w[6][0]+320,-w[6][1]+240,w[1][0]+320,-w[1][1]+240);
line(w[5][0]+320,-w[5][1]+240,w[2][0]+320,-w[2][1]+240);

getch();
closegraph();

}
