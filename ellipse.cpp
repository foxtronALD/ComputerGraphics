#include <stdio.h>
#include <graphics.h>

void elipse(int xc,int yc,int a,int b)
{

   int x=0, y=b;
   int p=(b*b)-(a*a*b)+((a*a)/4);

   while((2*x*b*b)<(2*y*a*a))
   {
        putpixel(xc+x,yc-y,3);
        putpixel(xc-x,yc+y,3);
        putpixel(xc+x,yc+y,3);
        putpixel(xc-x,yc-y,3);
        delay(100);
        if(p<0)
       {
	     x++;
	     p+=((2*b*b*x)+(b*b));
        }
        else
        {
     		x++;
     		y--;
		p+=((2*b*b*x+b*b)-(2*a*a*y));
        }
   }
   p=((float)x+0.5)*((float)x+0.5)*b*b + (y-1)*(y-1)*a*a - a*a*b*b;

   while(y>=0)
   {
        putpixel(xc+x,yc-y,7);
        putpixel(xc-x,yc+y,7);
        putpixel(xc+x,yc+y,7);
        putpixel(xc-x,yc-y,7);
	delay(100);
        if(p>0)
        {
		y--;
    		p-=((2*a*a*y)+(a*a));
        }
        else
       {
	     y--;
	     x++;
 	    p+=((2*b*b*x)-(2*a*a*y)-(a*a));
       }
   }
   closegraph();
}

int  main()
 {
	  int gm=DETECT,gd;
	  initgraph(&gm,&gd,"");
	  elipse(250,250,200,80);
 	  return 0;
 }
