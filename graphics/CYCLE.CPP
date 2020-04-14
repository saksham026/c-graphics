#include<iostream.h>
#include<conio.h>
#include<process.h>
int q[4][4],track[4],sta[4]={0,0,0},start;
int i,j,k,c,set,over=0,store,cyl[10],x=0,flag=0;
int queue[10],top=-1,adj[4];
void check();
void status()
{

  for(i=0;i<4;i++)
  {
  if(queue[top]==track[i])
  {
  k=i;
  }
  }
  for(i=0;i<4;i++)
  {
  if(i==k)
  {
   sta[i]=1;
  }
  }
}
void traverse()
{
cout<<"give me a strating point"<<endl;
cout<<"from"<<endl;
for(i=0;i<4;i++)
{
cout<<track[i]<<endl;
}
cout<<"enter"<<endl;
cin>>start;
top++;                  //enqueue()
queue[top]=start;
store=queue[top];
cyl[x]=queue[top];
status();
top--;
do
{

   for(i=0;i<4;i++)
  {
  if(store==track[i])
  {
  set=i;
  }
  }
 c=0;
 for(j=0;j<4;j++)
 {
  if(q[set][j]==1)
  {

   adj[c]=track[j];
   c++;

  }
 }
 int temp;
   for(i=0;i<c;i++)
   {
   for(j=i+1;j<c;j++)
   {
      if(adj[i]>adj[j])
      {
       temp=adj[i];
       adj[i]=adj[j];
       adj[j]=temp;
      }
   }

   }

   if(c==0)
   {
     top--;
   }
   else
   {
    int p=0;
    for(int m=0;m<4;m++)
    {
    if(p==0)
    {
    for(i=0;i<4;i++)
  {
  if(adj[c-1-m]==track[i])
  {
  k=i;

 if(sta[k]==0)
 {
  cyl[x]=adj[c-1-m];
  p=1;
  break;
  }
 }
 }
 }
 }
   for(j=0;j<c;j++)
   {
   for(i=0;i<4;i++)
  {
  if(adj[j]==track[i])
  {
  k=i;

 if(sta[k]==0)
 {
   top++;
   queue[top]=adj[j];
   status();
 }
 else
 {

   flag=1;
   break;

 }
  }
  }
  }

   store=queue[top];
   top--;
  }
 over=0;
 for(i=0;i<4;i++)
 {

  if(sta[i]==1)
  {
  over++;
  }

 }


}while(top!=-1||over!=4);

}
void allocate()
{
 int spr;
 for(i=0;i<4;i++)
 {
 for(j=0;j<4;j++)
 {
   cout<<"is there a relation between"<<track[i]<<"and"<<track[j]<<endl;
   cout<<"press 1 if there is relation  else press 0"<<endl;
   cin>>spr;
   if(spr==1)
   q[i][j]=1;
   else if(spr==0)
   q[i][j]=0;
   else
   cout<<"wrong value considered to be zero"<<endl;

 }
   cout<<endl;
 }
 check();

}
void check()
{
 cout<<"adjacency matrix for graph"<<endl;
 for(i=0;i<4;i++)
 {
 for(j=0;j<4;j++)
 {
 cout<<q[i][j]<<" ";
 }
 cout<<endl;
 }

}
void create()
{
 cout<<"enter values";
 for(i=0;i<4;i++)
 {
  cout<<"value"<<i+1<<endl;
  cin>>track[i];

 }
 allocate();
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
 create();
 break;
 case 2:
 traverse();
 if(flag==1)
 cout<<"graph consist a cycle"<<endl;
 else
 cout<<"no cycle"<<endl;
 for(i=0;i<x;i++)
 {
 cout<<cyl[i];
 }

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