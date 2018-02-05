#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void bresenham(int x1, int y1, int x2, int y2)
{
   int m = 2 * (y2 - y1);
   int slope=m-(x2 - x1),x,y;
   for (x = x1, y = y1; x <= x2; x++)
   {
     putpixel(x,y,RED);
     slope=slope+ m;
     if(slope>= 0)
      {
         y++;
         slope=slope-(2 * (x2 - x1));
      }
      delay(100);
   }
}

int main()
{
  int gd = DETECT, gm;
  initgraph (&gd, &gm,"");
  int x1 = 100, y1 = 150, x2 = 300, y2 = 400;
  bresenham(x1, y1, x2, y2);
  return 0;
}
