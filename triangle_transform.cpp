#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define SIN(x) sin(x * 3.141592653589/(float)180)
#define COS(x) cos(x * 3.141592653589/(float)180)
void translate(float a[][2],float t[2])
{
 setcolor(4);
 int i;
 for(i=0;i<3;i++)
 {
    a[i][0]+=t[0];
    a[i][1]+=t[1];
 }
 for(i=0;i<2;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[2][0],a[2][1],a[0][0],a[0][1]);
}
void scale(float a[][2],float s[2])
{
 int gd=DETECT,gm;
 setcolor(6);
 int i;
 for(i=0;i<3;i++)
  {
   a[i][0]*=s[0];
   a[i][1]*=s[1];
  }
 for(i=0;i<2;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[2][0],a[2][1],a[0][0],a[0][1]);
 float t[2];
 t[0]=10;
 t[1]=20;
 translate(a,t);
}
void rotate(float a[][2],float x,float y,float angle)
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 setcolor(8);
 int i=0;
 for(i=0;i<2;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[2][0],a[2][1],a[0][0],a[0][1]);
 i=0;
 while(i<3)
  {
   float xs=a[i][0]-x;
   float ys=a[i][1]-y;
   a[i][0]=x+(xs*COS(angle)-ys*SIN(angle));
   a[i][1]=y+(xs*SIN(angle)+ys*COS(angle));
   i++;
  }
 setcolor(7);
 float s[2];
 s[0]=0.5;
 s[1]=0.5;
 scale(a,s);
 delay(10000);
}
int main()
{
 float a[10][2],angle=30,x=200,y=150;
 int i;
 printf("enter coordinates of rectangle to be rotated \n");
 for(i=0;i<3;i++)
  scanf("%f%f",&a[i][0],&a[i][1]);
 /*printf("enter angle : ");
 scanf("%f",&angle);
 printf("enter pivot point : ");
 scanf("%f%f",&x,&y);
 */rotate(a,x,y,angle);
 return 0;
}
