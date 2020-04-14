#include<stdio.h>
#include<conio.h>
int a[5],val;
int front=-1,rear=-1,i;
void enqueue()
{
  if(rear==4)
  {
  printf("queue is full");
  }
  else
  {
  printf("enter values");
  scanf("%d",&val);
  if(front==-1&&rear==-1)
  {
    front=rear=0;
    a[rear]=val;
  }
  else
  {
   rear++;
   a[rear]=val;

  }
  }

}
void dequeue()
{
if(front==-1)
{
printf("queue is empty");
}
else if(front==rear)
{
printf("val deleted is%d",a[front]);
front=rear=-1;
}
else
{
printf("val deleted is%d",a[front]);
front++;
}

}
void display()
{
printf("values are");
for(i=front;i<=rear;i++)
{
  if(front==-1&&rear==-1)
  {
   printf("no elements to dipslay");
  }
   else
   printf("%d",a[i]);

}

}
void main()
{
int p=1,ch;
clrscr();
do
{
printf("enter 1 for isertion\n 2 for deletion\n for display\n 4 for exit");
printf("enter yor choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit();
break;
default:printf("wrong choice");
}
}while(p!=0);
getch();
}