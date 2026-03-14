#include<stdio.h>
#include<math.h>
#define PI 3.14159
int main(){
    int r,h;
    scanf("%d%d",&h,&r);
    double v;
    v=PI*r*r*h;
    int n=ceil(20*1000/v);
    printf("%d\n",n);
    return 0;
}