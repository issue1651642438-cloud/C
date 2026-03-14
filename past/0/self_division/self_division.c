#include<stdio.h>
int main(){
    int n=0,i=0;
    int a=0,b=0,c=0;
    scanf("%d",&n);
    for(i=10;i<=n;i++){
        a=i/10;
        b=i%10;
        c=a+b;
        if(i%c==0) printf("%d\n",i);
    }
    return 0;
}