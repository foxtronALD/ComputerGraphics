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
 int d=1-r;
 while(y>=x)
 {
   draw(xc,yc,x,y);
   x++;
   if(d>0)
   {
      y--;
      d=d+2*(x-y)+1;
   }
   else
      d=d+2*x+1;
   draw(xc,yc,x,y);
   delay(200);
 }
}
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  circl(200,200,50);
  return 0;
}
