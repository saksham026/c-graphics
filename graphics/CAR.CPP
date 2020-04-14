#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void distance(int lim)
{
  float dist;
  float fr;
  fr=(float)lim/4;
  dist=lim+fr;
  cout<<endl;
  cout<<"maximum distance which can be covered by your car is"<<dist<<endl;
}
void tyre()
{
   int lim;
   cout<<endl<<endl;
   cout<<"hello sir what can i help you"<<endl;
   cout<<"user: I want to find max distance my car can cover"<<endl;
   cout<<"please specify lifetime of your car's tyre"<<endl;
   cin>>lim;
   distance(lim);

}
void main()
{
  clrscr();
  tyre();
  getch();

}