#include<stdio.h>
int main(){
    float a;
    double b;

    scanf("%f%lf",&a,&b);

    printf("%f\n%.3f\n%.5e\n%g\n",a,b,b,b);

    return 0;
}