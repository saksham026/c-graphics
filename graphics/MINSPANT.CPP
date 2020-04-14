#include<iostream.h>
#include<conio.h>
#include<process.h>
int q[4][4],weight=0,edge=0;
int i,j,k,c,f,arr[16],sync[16],sync2[16],mst[4][4]={0},we;
int d[4][4]={0},h;
void check();
/* void status()
{

  for(i=0;i<5;i++)
  {
  if(queue[cnt]==track[i])
  {
  k=i;
  }
  }
  for(i=0;i<5;i++)
  {
  if(i==k)
  {
   sta[i]=1;
  }
  }
} */
void print()
{
 cout<<"spanning tree for graph"<<endl;
 for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {
 cout<<mst[i][j]<<" ";
 }
 cout<<endl;
 }

}
int cycle()
{

    for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {

   for(h=1;h<=4;h++)
   {
     d[i][j]+=mst[i][h]*mst[h][j];
 }
 }
 }


  f=0;
     for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {
   if(i==j)
   {
    if(d[i][j]!=0)
    {
      f=1;
      break;
    }
   }
   }
   }

   return f;

}
void spantree()
{
     int cnt=1;
     cout<<"spanning tree is"<<endl;

     mst[sync[cnt]][sync2[cnt]]=arr[cnt];
     weight=weight+arr[cnt];
     edge++;
     cnt++;
     do
     {

     mst[sync[cnt]][sync2[cnt]]=arr[cnt];
     weight=weight+arr[cnt];
     if(cycle())
     {
       mst[sync[cnt]][sync2[cnt]]=0;
     }
     else
     {
      edge++;
     }
     cnt++;
     }while(edge!=3);
     print();

}
void sort()
{
 int temp;
 for(i=0;i<k;i++)
 {
   for(j=i+1;j<k;j++)
   {
      if(arr[i]>arr[j])
      {
	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;
	 temp=sync[i];
	 sync[i]=sync[j];
	 sync[j]=temp;
	 temp=sync2[i];
	 sync2[i]=sync2[j];
	 sync2[j]=temp;

      }

   }
 }
 spantree();
}

void collect()
{

  k=0;
  for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {
 if(q[i][j]!=0)
 {
 arr[k]=q[i][j];
 sync[k]=i;
 sync2[k]=j;
 k++;
 }
 }
 }
 sort();
}
void allocate()
{

 int spr;
 for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {
   cout<<"is there a relation between"<<i<<"and"<<j<<endl;
   cout<<"press 1 if there is relation  else press 0"<<endl;
   cin>>spr;
   if(spr==1)
   {
   cout<<"give weight between"<<i<<"and"<<j<<endl;
   cin>>we;
   q[i][j]=we;
   }
   else if(spr==0)
   {
   q[i][j]=0;
   }
   else
   cout<<"wrong value considered to be zero"<<endl;

 }

 }
 check();

}
void check()
{
 cout<<"adjacency matrix for graph"<<endl;
 for(i=1;i<=4;i++)
 {
 for(j=1;j<=4;j++)
 {
 cout<<q[i][j]<<" ";
 }
 cout<<endl;
 }

}
void main()
{
int ch;
clrscr();
while(1)
{
cout<<"press 1 for create 2 for traversing 3 for exit"<<endl;
cout<<"enter your choice"<<endl;
cin>>ch;
switch(ch)
{
 case 1:
 allocate();
 break;
 case 2:
 collect();
 break;
 case 3:
 exit(0);
 break;
 default:
 cout<<"wrong choice";
}
}
getch();
}