#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    double c[n],f[n];
    for(i=0;i<n;i++){
        scanf("%lf",&f[i]);
        c[i]=5*(f[i]-32)/9;
    }
    for(i=0;i<n;i++){
        printf("%.5f\n",c[i]);
    }
    return 0;
}