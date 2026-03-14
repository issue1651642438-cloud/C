#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    int num[10005];
    int yxnum=0,bjgnum=0;
    double yx,bjg;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]>=85) yxnum++;
        if(num[i]<60) bjgnum++;
    }

    yx=1.0*yxnum/n;
    bjg=1.0*bjgnum/n;

    if(yx>=0.514)
    {
        printf("ERLE\n");
    }
    if(bjg>0.114)
    {
        printf("FRLE\n");
    }

    if(!(yx>=0.514||bjg>0.114))
    {
        printf("Accepted\n");
    }
}