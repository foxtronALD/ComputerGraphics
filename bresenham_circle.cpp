#include<stdio.h>
#include<graphics.h>
void draw(int xc,int yc,int x,int y)
{
   putpixel(xc+x,yc-y,3);
   putpixel(xc-x,yc+y,3);
   putpixel(xc+x,yc+y,3);
   putpixel(xc-x,yc-y,3);

   putpixel(xc+y,yc-x,3);
   putpixel(xc-y,yc+x,3);
   putpixel(xc+y,yc+x,3);
   putpixel(xc-y,yc-x,3);
}
void circl(int xc,int yc,int r)
{
 int x=0,y=r;
 int d=3-2*r;
 while(y>=x)
 {
   draw(xc,yc,x,y);
   x++;
   if(d>0)
   {
     y--;
     d=d+4*(x-y)+10;
   }
   else
     d=d+4*x+6;
   draw(xc,yc,x,y);
   delay(200);
  }
}
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  circl(300,300,80);
  return 0;
}
