#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
       void rot()
      {
	float a=120,b=120;
	float p=0.785398;

	while(!kbhit())
	{
		cleardevice();
		line(100,145,500,545);
		a=a+1;
		b=b+1;
		line(a+30*cos(p),b+30*sin(p),a+30*cos(p+2*0.785398),b+30*sin(p+2*0.785398));
		line(a+30*cos(p+2*0.785398),b+30*sin(p+2*0.785398),a+30*cos(p+4*0.785398),b+30*sin(p+4*0.785398));
		line(a+30*cos(p+4*0.785398),b+30*sin(p+4*0.785398),a+30*cos(p+6*0.785398),b+30*sin(p+6*0.785398));
		line(a+30*cos(p+6*0.785398),b+30*sin(p+6*0.785398),a+30*cos(p),b+30*sin(p));

		delay(10);

		p+=0.026;
	  }
   }
void main(){
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rot();
	getch();
}
