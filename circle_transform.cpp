#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define SIN(X) sin(x*3.14/(float)180)
#define COS(X) cos(x*3.14/(float)180)
float a[2],s,t[2];

void translate(float a[],float r,float t[])
{
	a[0]+=t[0];
	a[1]+=t[1];
	setcolor(3);
	circle(a[0],a[1],r);
    delay(1000);
}

void scale(float a[],float r,float s)
{   r=r*s;
	setcolor(6);
	circle(a[0],a[1],r);

	t[0]=t[1]=40;
	translate(a,r,t);
	delay(1000);
}

void rotate(float a[],float r,float angle,float x,float y)
{

	float xs= a[0]-x;
	float ys= a[1]-y;

	a[0]= x + (xs*COS(angle) - ys*SIN(angle));
	a[1]= y + (xs*SIN(angle) + ys*COS(angle));
	setcolor(8);
	circle(a[0],a[1],r);

	float s=2;
	scale(a,r,s);
	delay(1000);
}

int main()
{
	printf("Enter the CENTRE coordinates\n");
	scanf("%f%f",&a[0],&a[1]);

	float r;
	printf("Enter the radius\n");
	scanf("%f",&r);

	float angle=30;
	float x=100,y=100;

    int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setcolor(5);
	circle(a[0],a[1],r);

	rotate(a,r,angle,x,y);
	return 0;
}
