#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<graphics.h>

void bspline(double x[4],double y[4])
{
    int i;
    double a[4],b[4],sx[4],sy[4];

    int div=sqrt(pow((x[1]-x[0]),2)+pow((y[1]-y[0]),2));

    a[0]=(-x[0]+3*x[1]-3*x[2]+x[3])/(double)6.0;
    a[1]=(3*x[0]-6*x[1]+3*x[2])/(double)6.0;
    a[2]=(-3*x[0]+3*x[2])/(double)6.0;
    a[3]=(x[0]+4*x[1]+x[2])/(double)6.0;

    b[0]=(-y[0]+3*y[1]-3*y[2]+y[3])/(double)6.0;
    b[1]=(3*y[0]-6*y[1]+3*y[2])/(double)6.0;
    b[2]=(-3*y[0]+3*y[2])/(double)6.0;
    b[3]=(y[0]+4*y[1]+y[2])/(double)6.0;

    sx[0]=a[3];
    sy[0]=b[3];

    for(i=1;i<=div;i++)
    {
        float t;
        t=(float)i/(float)div;
        sx[i]=a[3]+t*(a[2]+t*(a[1]+t*a[0]));
        sy[i]=b[3]+t*(b[2]+t*(b[1]+t*b[0]));
        putpixel(sx[i],sy[i],YELLOW);
    }
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    double x[4]={100,300,400,450};
    double y[4]={100,200,300,450};
    bspline(x,y);
    return 0;
}
