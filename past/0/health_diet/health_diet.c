#include<stdio.h>
int main(){
    int a,b,c,d;
    double x;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    x=(double)(a*1.1+b*1.2+c*22.5+d*8.8);
    if(x<=1000&&x>=600){
        printf("FINE\n");
    }else if(x<600){
        printf("UNDER\n");
    }else {
        printf("OVER\n");
    }
    return 0;
}