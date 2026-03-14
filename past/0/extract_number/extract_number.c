#include<stdio.h>
int main(){
    int n[30],k=0,k0=0,i=0;
    int a,b,c,d;
    scanf("%d",&k);

    for(i=0;i<k;i++){
        scanf("%d",&n[i]);
        a=n[i]/1000;
        b=(n[i]/100)%10;
        c=(n[i]/10)%10;
        d=n[i]%10;
        if((d-a-b-c)>0 ) k0++ ;

       // printf("%d\n%d\n%d\n%d\n%d\n",a,b,c,d,k0);
    }
    printf("%d",k0);
    return 0;
}