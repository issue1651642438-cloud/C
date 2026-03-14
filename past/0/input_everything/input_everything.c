#include<stdio.h>
int main(){
    char a;
    int b;
    float c;
    double d;

    scanf("%c\n",&a);
    scanf("%d\n",&b);
    scanf("%f\n",&c);
    scanf("%lf",&d);

    printf("%c %d %.6f %.6f",a,b,c,d);
    return 0;
}