#include<stdio.h>
int main(){
    int n=0,i,j;
    long long int num=0,n0=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        n0=1;
        for(j=1;j<=i;j++){
            n0*=j;
        }
        num+=n0;
    }
    printf("%lld",num);
    return 0;
}