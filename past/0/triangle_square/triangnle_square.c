#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,r,s;
    scanf("%lf%lf%lf",&a,&b,&c);

    r=(a+b+c)*0.5;

    if(a+b>c&&a+c>b&&b+c>a){
        s=sqrt(r*(r-a)*(r-b)*(r-c));
        printf("%.4f",s);
    }else{
        printf("Data Error");
    }
    return 0;
}