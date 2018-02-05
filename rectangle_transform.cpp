#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define SIN(x) sin(x * 3.141592653589/(float)180)
#define COS(x) cos(x * 3.141592653589/(float)180)
void translate(float a[][2],float t[2])
{
 setcolor(4);
 int i;
 for(i=0;i<4;i++)
 {
    a[i][0]+=t[0];
    a[i][1]+=t[1];
 }
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
 delay(1000);
}
void scale(float a[][2],float s[2])
{
 //int gd=DETECT,gm;
 setcolor(6);
 int i;
 for(i=0;i<4;i++)
  {
   a[i][0]*=s[0];
   a[i][1]*=s[1];
  }
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);

 float t[2];
 t[0]=100;
 t[1]=200;
 translate(a,t);
  delay(1000);
}
void rotate(float a[][2],float x,float y,float angle)
{
    int i;
 setcolor(8);
 for(i=0;i<4;i++)
 {
   float xs=a[i][0]-x;
   float ys=a[i][1]-y;
   a[i][0]=x+(xs*COS(angle)-ys*SIN(angle));
   a[i][1]=y+(xs*SIN(angle)+ys*COS(angle));
  }
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);

 float s[2];
 s[0]=3;
 s[1]=3;
 scale(a,s);
 delay(1000);
}
int main()
{
 float a[10][2],angle=30,x=200,y=150;
 int i;
 printf("enter coordinates of rectangle to be rotated \n");
 for(i=0;i<4;i++)
  scanf("%f%f",&a[i][0],&a[i][1]);
  int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 for(i=0;i<3;i++)
    line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);

rotate(a,x,y,angle);
 return 0;
}
