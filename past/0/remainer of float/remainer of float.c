#include<stdio.h>
#include<math.h>
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    double r=fmod(a,b);
    printf("%.4f",r);
    return 0;
}