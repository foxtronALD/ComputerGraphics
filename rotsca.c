#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define SIN(x) sin(x * 3.141592653589/(float)180)
#define COS(x) cos(x * 3.141592653589/(float)180)  
void scale(float a[][2],float s[2])
{
 int gd=DETECT,gm;
 //initgraph(&gd,&gm,"");
 setcolor(4);
 int i;
 for(i=0;i<4;i++)
  {
   a[i][0]*=s[0];
   a[i][1]*=s[1];
  }
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
} 
void rotate(float a[][2],float x,float y,float angle)
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 setcolor(2);
 int i=0;
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
 i=0;
 while(i<4)
  {
   float xs=a[i][0]-x;
   float ys=a[i][1]-y;
   a[i][0]=x+(xs*COS(angle)-ys*SIN(angle));
   a[i][1]=y+(xs*SIN(angle)+ys*COS(angle));
   i++;
  }
 setcolor(3);
 /*for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
 */float s[2];
 //printf("enter translation factor : ");
 //scanf("%f%f",t[0],t[1]);
 s[0]=0.5;
 s[1]=0.5;
 scale(a,s);
 delay(10000);
}
int main()
{
 float a[10][2],angle,x,y;
 int i;
 printf("enter coordinates of rectangle to be rotated \n");
 for(i=0;i<4;i++)
  scanf("%f%f",&a[i][0],&a[i][1]);
 printf("enter angle : ");
 scanf("%f",&angle);
 printf("enter pivot point : ");
 scanf("%f%f",&x,&y);
 rotate(a,x,y,angle);
 return 0;
}
