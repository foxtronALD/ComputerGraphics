#include<graphics.h>
#include<stdio.h>

int inside=0;
int left=1;
int right=2;
int down=4;
int up=8;
double x1,y1,x2,y2,p1,q1,p2,q2;

int get_binarycode(double x,double y)
{
    int c=inside;
    if(x<x1)
        c = c | left;
    else if(x>x2)
        c = c | right;
    else if(y<y1)
        c = c | down;
    else if(y>y2)
        c = c | up;

    return c;
}

void lineclipping(void)
{
    int c1=get_binarycode(p1,q1);
    int c2=get_binarycode(p2,q2);
    int flag=0,x,y,out;

    while(1)
    {
        if(c1==0 && c2==0)
        {
            flag=1;
            break;
        }
        else if(c1 & c2)
            break;
        else
        {
            if(c1!=0)
                out=c1;
            else
                out=c2;

            if(out & left)
            {
                x=x1;
                y=q1+((q2-q1)/(p2-p1))*(x1-p1);
            }
            else if(out & right)
            {
                x=x2;
                y=q1+((q2-q1)/(p2-p1))*(x2-p1);
            }
            else if(out & up)
            {
                y=y2;
                x=(y-q1)*(p2-p1)/(q2-q1)+p1;
            }
            else
            {
                y=y1;
                x=(y-q1)*(p2-p1)/(q2-q1)+p1;
            }
            if(c1==out)
            {
                p1=x;
                q1=y;
                c1=get_binarycode(x,y);
            }
            else
            {
                p2=x;
                q2=y;
                c2=get_binarycode(x,y);
            }
        }
    }
    if(flag==0)
            printf("line is rejected\n");
    else
            printf("line is accepted\n");
}

int main()
{
    printf("Enter the two corner coordinates of Rectangle\n");
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);

    printf("Enter the coordinates of the Line\n");
    scanf("%lf%lf%lf%lf",&p1,&q1,&p2,&q2);

    lineclipping();

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    rectangle(x1,y1,x2,y2);
    line(p1,q1,p2,q2);

    delay(1000);
    return 0;
}
