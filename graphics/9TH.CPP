#include <graphics.h>
#include <dos.h>
#include <conio.h> 
 
main()
{
   int i, j = 0, gd = DETECT, gm;
 
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");

   for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      setcolor(2);
      delay(100);

      if( i == 420 )
	 break;

      clearviewport();
   }

   getch();
   closegraph();
   return 0;
}