#include<stdio.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=0;i<32;i++){
        sum+=(n>>(i))&1;
    }
    if(sum%2==0){
        printf("EVEN");
    }else{
        printf("ODD");
    }
    return 0;
}