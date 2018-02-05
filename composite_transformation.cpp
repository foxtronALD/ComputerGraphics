#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
int main()
{
				float i,xa[10],ya[10],xa1[10],ya1[10],xa2[10],ya2[10],xa3[10],ya3[10];
				int n;
				float tx,ty,sx,sy,xf,yf,rx,ry;
				float ang;

				printf("Enter the number of vertices:\n");
				scanf("%d",&n);
				printf("Enter the coordinates:\n");
				for(i=0;i<n;i++)
					scanf("%f%f",&xa[i],&ya[i]);

				printf("ORIGINAL FIGURE:\n");
				int gd=DETECT,gm;
				initgraph(&gd,&gm,"");
				setcolor(6);
				for(i=0;i<n;i++)
					line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
				delay(1000);
				closegraph();

				printf("Enter the Translation factor\n");
				scanf("%f%f",&tx,&ty);
				for(i=0;i<n;i++)
				{
					xa1[i]=xa[i]+tx;
					ya1[i]=ya[i]+ty;
				}
				printf("After Translation\n");
				initgraph(&gd,&gm,"");
				setcolor(2);
				for(i=0;i<n;i++)
					line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);
				delay(1000);
				closegraph();

				printf("Enter the Rotation Angle\n");
				scanf("%f",&ang);
				ang=(ang*3.14)/180;
				printf("Enter the Reference points\n");
				scanf("%f%f",&xf,&yf);
				for(i=0;i<n;i++)
				{
					xa2[i]= xf+ (xa1[i]-xf)*cos(ang)- (ya1[i]-yf)*sin(ang);
					ya2[i]= yf+ (xa1[i]-xf)*sin(ang)- (ya1[i]-yf)*cos(ang);
				}
				printf("After Rotation\n");
				initgraph(&gd,&gm,"");
				setcolor(3);
				for(i=0;i<n;i++)
					line(xa2[i],ya2[i],xa2[(i+1)%n],ya2[(i+1)%n]);
				delay(1000);
				closegraph();

				printf("Enter the Scaling factor\n");
				scanf("%f%f",&sx,&sy);
				printf("Enter the Reference points\n");
				scanf("%f%f",&rx,&ry);
				for(i=0;i<n;i++)
				{
					xa3[i]= xa2[i]*sx +rx*(1-sx);
					ya3[i]= ya2[i]*sy +ry*(1-sy);
				}
				printf("After Scaling\n");
				initgraph(&gd,&gm,"");
				setcolor(4);
				for(i=0;i<n;i++)
					line(xa3[i],ya3[i],xa3[(i+1)%n],ya3[(i+1)%n]);
				delay(1000);
				closegraph();

				return 0;
	}

