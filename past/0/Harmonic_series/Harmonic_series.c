#include<stdio.h>
int main()
{
    
    int n,i,j;
    long number;
    double e=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        number=1;
        for(j=1;j<=i;j++){
            number*=j;
        }
        e+=(double)1/number;
        

       // printf("%d %f %ld\n",i,e,number);
    }
    printf("%.4lf",e);
    return 0;
}