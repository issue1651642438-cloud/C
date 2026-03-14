#include<stdio.h>
#include<math.h>
int is_in(long long int x)
{
    long long int a0=0;
    int i;
    while(x>a0){
        a0=2*a0+1;
    }
    if(a0==x){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

int main()
{
    long long int x;
    while(scanf("%lld",&x)==1){
        is_in(x);
    }
    return 0;
}