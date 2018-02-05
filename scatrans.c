#include<stdio.h>
#include<graphics.h>
#include<math.h>
void translate(float a[][2],float t[2])
{
 int gd=DETECT,gm;
 //initgraph(&gd,&gm,"");
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
} 
void scale(float a[][2])
{
 int gd=DETECT,gm;
 float s[2];
 initgraph(&gd,&gm,"");
 setcolor(2);
 int i=0;
 for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
 i=0;
 s[0]=0.5;
 s[1]=0.5;
 while(i<4)
  {
   a[i][0]=a[i][0]*s[0];
   a[i][1]=a[i][1]*s[1];
   i++;
  }
 setcolor(3);
 /*for(i=0;i<3;i++)
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 line(a[3][0],a[3][1],a[0][0],a[0][1]);
 */float t[2];
 //printf("enter translation factor : ");
 //scanf("%f%f",t[0],t[1]);
 t[0]=10;
 t[1]=20;
 translate(a,t);
 delay(10000);
}
int main()
{
 float a[10][2],x,y;
 int i;
 printf("enter coordinates of rectangle to be rotated \n");
 for(i=0;i<4;i++)
  scanf("%f%f",&a[i][0],&a[i][1]);
 scale(a);
 return 0;
}
