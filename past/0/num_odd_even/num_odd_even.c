#include<stdio.h>
int main ()
{
    int a[8],i;
    for (i=0;i<8;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            a[i]-=1;
        }else{
            a[i]+=1;
        }
    }
    for (i=0;i<7;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[7]);
    return 0;
}