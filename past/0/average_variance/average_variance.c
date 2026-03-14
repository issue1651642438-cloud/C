#include<stdio.h>
int main (){
    int n,i;
    double average,s_2,sum=0,sum_=0;
    scanf("%d",&n);
    double a[n];
    for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
        sum+=a[i];
    }
    average=sum/n;
    for(i=0;i<n;i++){
        sum_+=(a[i]-average)*(a[i]-average);
    }
    s_2=sum_/n;

    printf("%.5f %.5f",average,s_2);
    return 0;
}