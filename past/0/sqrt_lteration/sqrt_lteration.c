#include<stdio.h>
#include<math.h>
int main(){
    int i;
    double a[20];
    scanf("%lf",&a[0]);
    a[1]=0.5*(a[0]+a[0]/a[0]);
    i++;
    for(i=1;i<20;i++){
       
        a[i+1]=0.5*(a[i]+a[0]/a[i]);
        // printf("%lf,%2d\n",a[i],i);
        if(fabs(a[i]-a[i-1])<=0.00001) break;
        
    }
    printf("%.7lf",a[i]);
}