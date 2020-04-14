#include<iostream.h>
#include<conio.h>
void hanoi(int n,char*a,char *b,char *c)
{
  if(n==1)
  {
    cout<<"move disc from  "<<a<<"  to  "<<c<<endl;
    return;
  }
  else
  {
    hanoi(n-1,a,c,b);
    cout<<"move disc from  "<<a<<"  to  "<<c<<endl;
    hanoi(n-1,b,a,c);
    return;

  }
}
void main()
{

int n;
clrscr();
cout<<"enter no of discs"<<endl;
cin>>n;
hanoi(n,"t1","t2","t3");
getch();

}