#include<stdio.h>
#include<math.h>
int main(){
    double r1,r2;
    scanf("%lf%lf",&r1,&r2);
    double r=1/(1/r1+1/r2);
    printf("%.2f\n",r);
    return 0;
}