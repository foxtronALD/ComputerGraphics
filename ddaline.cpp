#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int abs(int n)
{
    return ( (n>0) ?  n : ((-1)*n) );
}
void dda(float a,float b,float c,float d)
{
    float dx=abs(c-a);
    float dy=abs(d-b);

    float steps = dx>=dy ? dx : dy;

    dx= dx/steps;
    dy= dy/steps;

    float x=a;
    float y=b;

    for(int i=1;i<=steps;i++)
    {
        putpixel(x,y,RED);
        x+=dx;
        y+=dy;
        delay(100);
    }
    closegraph();
}
int main()
{
    int gd= DETECT,gm;
    initgraph(&gd,&gm,"");
    float a=100,b=150,c=300,d=400;
    dda(a,b,c,d);
    return 0;
}
