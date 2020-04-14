#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
float mat[2][2];
int q[4][2];
int d[4][2];
int x2[4],x3[4],y2[4],y3[4],tx,ty,g;
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

  // cout<<"mat"<<a<<b<<endl;
}
void rot()
{
  float w;
  cout<<"enter rotate factor for x and y respectively"<<endl;
  cin>>w;


  matrix(w);
  for(int k=0;k<4;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

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
  for(int k=0;k<4;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

  }

}
void matrix2(float b)
{
   mat[0][0]=1;
   mat[1][1]=1;
   mat[0][1]=0;
   mat[1][0]=b;

  // cout<<"mat"<<a<<b<<endl;
}
void shear()
{
  float shx,shy;
  cout<<"enter shear factor for y respectively"<<endl;
  cin>>shy;

  matrix2(shy);
  for(int k=0;k<4;k++)
  {
    for(int j=0;j<2;j++)
    {
     d[k][j]=q[k][0]*mat[0][j]+q[k][1]*mat[1][j];

     }

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

clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

int r=getmaxx();
int u=getmaxy();
//cout<<"x"<<r<<endl;
//cout<<"y"<<u<<endl;


//cout<<sin(30*3.14/180);


dda(0,u/2,r,u/2,4);
dda(r/2,0,r/2,u,4);

//cout<<"menu 1>rotation  2>translation  3>scaling"<<endl;
//cout<<"enter cordinates for line"<<endl;
//cin>>x2[0];
//cin>>y2[0];

q[0][0]=30;
q[0][1]=30;   //40

//cout<<"enter cordinates for line 2"<<endl;
//cin>>x3[0];
//cin>>y3[0];

q[1][0]=80;
q[1][1]=30;


q[2][0]=80;
q[2][1]=80;


q[3][0]=30;
q[3][1]=80;
setcolor(RED);

int i=0,j;

for(j=0;j<4;j++)
{
i=i%3;
dda(q[i][0]+320,-q[i][1]+240,q[i+1][0]+320,-q[i+1][1]+240,1);
i++;
}
dda(q[3][0]+320,-q[3][1]+240,q[0][0]+320,-q[0][1]+240,1);

int ch,g=1;
//scale();
//cout<<"translated line"<<endl;



do
{

cout<<"enter choice 1>rotation 2>translation 3>scaling 4>reflection 5>shear"<<endl;
cin>>ch;
switch(ch)
{
int j;

case 1:
rot();

i=0;
for(j=0;j<4;j++)
{
i=i%3;
dda(d[i][0]+320,-d[i][1]+240,d[i+1][0]+320,-d[i+1][1]+240,4);
 i++;
}
dda(d[3][0]+320,-d[3][1]+240,d[0][0]+320,-d[0][1]+240,4);

break;

case 2:
tran();

    i=0;
for(j=0;j<4;j++)
{
i=i%3;
dda(q[i][0]+tx+320,-q[i][1]+ty+240,q[i+1][0]+tx+320,-q[i+1][1]+ty+240,4);
i++;
}
dda(q[3][0]+tx+320,-q[3][1]+ty+240,q[0][0]+tx+320,-q[0][1]+ty+240,4);

break;

case 3:
scale();

	i=0;
for(j=0;j<4;j++)
{
i=i%3;
dda(d[i][0]+320,-d[i][1]+240,d[i+1][0]+320,-d[i+1][1]+240,4);
i++;
}
dda(d[3][0]+320,-d[3][1]+240,d[0][0]+320,-d[0][1]+240,4);

break;
case 4:


	i=0;
for(j=0;j<4;j++)
{
i=i%3;
dda(q[i][1]+320,-q[i][0]+240,q[i+1][1]+320,-q[i+1][0]+240,4);
i++;
}
dda(q[3][1]+320,-q[3][0]+240,q[0][1]+320,-q[0][0]+240,4);

break;

case 5:
shear();

	i=0;
for(j=0;j<4;j++)
{
i=i%3;
dda(d[i][0]+320,-d[i][1]+240,d[i+1][0]+320,-d[i+1][1]+240,4);
i++;
}
dda(d[3][0]+320,-d[3][1]+240,d[0][0]+320,-d[0][1]+240,4);

break;


case 6:
g=0;
}

}while(g!=0);

getch();
closegraph();

 }