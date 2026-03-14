#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

int main()
{
    double d,h;
    scanf("%lf%lf",&d,&h);
    double r=d/2;
    double s=PI*r*r+PI*r*sqrt(r*r+h*h);
    double v=(PI*r*r*h)/3;

    printf("superficial area = %.5lf\n",s);
    printf("volume = %.5lf\n",v);
    return 0;
}