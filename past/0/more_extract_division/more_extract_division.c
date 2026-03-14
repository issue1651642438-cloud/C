#include<stdio.h>
int main()
{
    double a[5],b[5],division[5];
    int i=0;
   
    for(i=0;i<5;i++){
        scanf("%lf %lf",&a[i],&b[i]);
        division[i]=a[i]/b[i];
    } 
    for(i=0;i<4;i++){
        printf("%.*lf\n",i+1,division[i]);
    }
    printf("%.5lf",division[4]);
    return 0;
}