#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int i;
double t;

void bezier(int x[4],int y[4])
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");

    for(i=0;i<4;i++)
        putpixel(x[i],y[i],RED);

    for(t=0.0; t<1.0; t+=0.0005)
    {                                                                                              //x[] . [ (1-t) + (t) ]^3
        double xt= pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3]; //x[0].(1-t)^3 + x[1].3.t.(1-t)^2 + x[2].3.(1-t).t^2 + x[3].t^3
        double yt= pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
        putpixel(xt,yt,WHITE);
        delay(10);
    }
    closegraph();
    return;
}

int main()
{
    int x[4],y[4];
    printf ("Enter the coordinates of the four control points\n");
    for (i=0; i<4; i++)
        scanf("%d%d",&x[i],&y[i]);
    bezier(x,y);
}
