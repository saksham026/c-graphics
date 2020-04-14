#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
float mat[2][2];
int q[2][2];
int d[2][2];
int x2,x3,y2,y3,tx,ty,g;
void dda(int x,int y,int p,int q)
{

  setcolor(2);
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

    putpixel(x1,y1,RED);
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

  // cout<<"mat"<<a<<b<<endl;
}
void rot()
{
  float w;
  cout<<"enter rotate factor for x and y respectively"<<endl;
  cin>>w;


  matrix(w);
  for(int k=0;k<2;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

  }
   for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
     cout<<d[i][j]<<"  ";
	//=q[i][0]*mat[0][j]+q[i][1]*mat[1][j];
     }
     cout<<endl;

  }



}
void matrix1(float a,float b)
{
   mat[0][0]=a;
   mat[1][1]=b;
   mat[0][1]=mat[1][0]=0;

  // cout<<"mat"<<a<<b<<endl;
}
void scale()
{
  float sx,sy;
  cout<<"enter scale factor for x and y respectively"<<endl;
  cin>>sx;
  cout<<"enter second"<<endl;
  cin>>sy;

  matrix1(sx,sy);
  for(int k=0;k<2;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

  }
  cout<<"scaled matrix"<<endl;
   for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
     cout<<d[i][j]<<"  ";
	//=q[i][0]*mat[0][j]+q[i][1]*mat[1][j];

     }
     cout<<endl;

  }

}
void tran()
{
  cout<<"enter value of tx and ty";
  cin>>tx;
  cin>>ty;


}
void main()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\turboc3\bin");

int r=getmaxx();
int u=getmaxy();
//cout<<"x"<<r<<endl;
//cout<<"y"<<u<<endl;


//cout<<sin(30*3.14/180);

dda(0,u/2,r,u/2);
dda(r/2,0,r/2,u);

cout<<"menu"<<endl;
cout<<"enter cordinates for line"<<endl;
cin>>x2;
cin>>y2;

q[0][0]=x2;
q[0][1]=y2;


cout<<"enter cordinates for line 2"<<endl;
cin>>x3;
cin>>y3;

q[1][0]=x3;
q[1][1]=y3;

dda(x2+320,-y2+240,x3+320,-y3+240);

int ch,g=1;
//scale();
//cout<<"translated line"<<endl;



do
{

cout<<"enter choice"<<endl;
cin>>ch;
switch(ch)
{

case 1:
rot();
dda(d[0][0]+320,-d[0][1]+240,d[1][0]+320,-d[1][1]+240);

break;

case 2:
tran();
dda(x2+tx+320,-y2+ty+240,x3+tx+320,-y3+ty+240);

break;

case 3:
scale();
dda(d[0][0]+320,-d[0][1]+240,d[1][0]+320,-d[1][1]+240);

break;
case 4:
g=0;
}

}while(g!=0);
getch();
closegraph();

}