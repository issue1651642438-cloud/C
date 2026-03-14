#include<stdio.h>
int main(){
    long long int m=0,m0=0;
    int k=0,is_k=0;
    scanf("%lld %d",&m,&k);
    m0=m;

    int i;
    for (i=1;i<=6;i++){
        if(m%10==3){
            is_k++;
        }
        m/=10;
    }

    (is_k==k&&m0%19==0)?printf("YES\n"):printf("NO\n");

    //printf ("%lld \n%lld \n%d \n%d",m,m0,k,is_k);

    return 0;

}
