#include<stdio.h>
#include<conio.h>
int no,pos,count=0,j,a;
struct node
{
 int data;
 struct node *rp;
}*start;

struct node *getnode()
{
 struct node*s;
 s=(struct node *)malloc(sizeof(struct node));
 printf("enter value\n");
 scanf("%d",&s->data);
 s->rp=NULL;
 return s;
}

void insert()
{
 struct node *n;
 struct node *next;
 n=getnode();
  if(start==NULL)
 {
 start=n;
 count++;
 }
  else
 {
  printf("enter pos\n");
  scanf("%d",&pos);
  if(pos>count+1)
  {
   printf("canot add to %d",pos);
  }
  else
  {
   if(pos==1)
  {
    n->rp=start;
    start=n;
    count++;
  }
    else
   {
      if(pos>(count+1))
      {
      printf("wrong position");
      }
      else
      {
      struct node *p=start;
      for(j=1;j<pos-1;j++)
      {
       p=p->rp;
      }
      count++;
      next=p->rp;
      p->rp=n;
      n->rp=next;

      }
   }
   }
 }
}
void display()
{
 struct node *p=start;
  while(p!=NULL)
 {
  printf("%d\n",p->data);
  p=p->rp;
 }
}
void delete()
{
 if(start==NULL)
 {
  printf("empty");
 }
 else
 {
 struct node *temp;

  printf("enter position");
  scanf("%d",&pos);
  if(pos>count)
  {
  printf("cannot delete at this position");
  }
  else
  {
 if(pos==1)
 {

  temp=start;
  start=start->rp;
  temp->rp=NULL;
  free(temp);
  count--;
 }
 else
 {
  struct node *temp2;


  if(pos>count)
  {
   printf("wrong choice");
  }
  else
  {
  for(j=1,temp=start;j<pos-1;j++)
  {
  temp=temp->rp;
  }
  for(j=1,temp2=start;j<pos;j++)
  {
  temp2=temp2->rp;
  }

   temp->rp=temp2->rp;
   temp2->rp=NULL;
   free(temp2);
   count--;
  }
 }
 }
 }
}
void main()
{

 int az=1,f,c=0,ch,k=1;
 start=NULL;
 clrscr();
 do
 {
 az=1,c=0,k=1;
 printf("press 1 for insertion\n 2 for deletion\n 3 for display\n 4 for exit\n5for reverse ");
 printf("enter choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("enter no of times u want to insert\n");
 scanf("%d",&no);
  do
 {
  insert();
  az++;
 }while(no>=az);
 break;
 case 3:
 display();
 break;
 case 2:
 printf("enter no of vales u want to delete");
 scanf("%d",&f);
 do
 {
 c++;
 delete();
 }while(c<f);
 break;
 case 4:
 exit();
 default:printf("wrong choice");
 }
 }while(k!=0);
 getch();
 }