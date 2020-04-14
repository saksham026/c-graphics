#include<stdio.h>
int main()
{
 int pid;
 pid=getpid();
 printf("current process id %d",pid);

 printf("forling");
 pid=fork();

 if(pid<0)
 {
   exit(-1);
 }
 else if(pid==0)
 {
   printf("child process started and completed");

 }
 else
 {
   sleep(100);
   printf("parent process started and completed");
   while(1)
   {

   }

 }

}