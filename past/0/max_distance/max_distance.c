#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct dis{
    double x;
    double y;
};


double distence(struct dis*m,struct dis*n)
{
    double x0=m->x-n->x;
    double y0=m->y-n->y;
    double d=sqrt(x0*x0+y0*y0);
    return d;
}


int main()
{
    freopen ("max_distance.txt","r",stdin);
    int n;
    scanf("%d",&n);
    struct dis p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&(p+i)->x,&(p+i)->y);
    }
    if(n<=1) return 0;
    double max=distence(p,p+1);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(distence(p+j,p+i)>max) max=distence(p+j,p+i);
        }
    }

    printf("%.4lf",max);
    return 0;
}