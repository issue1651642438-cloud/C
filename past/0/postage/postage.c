#include<stdio.h>
int main(){

    int n=0,k=0;
    scanf("%d\n",&n);
    int weight[n];
    double money[n];
    char fast[n];

    for(k=0;k<n;k++){
        money[k]=0.8;
        scanf("%d %c",&weight[k],&fast[k]);
        if(fast[k]=='y'){
            money[k]+=2;
        }
        if(weight[k]<=1){
            money[k]+=0;
        }else{
            money[k]+=(double)(0.5*(weight[k]-1));
        }
    }
    for(k=0;k<n;k++){
        printf("%.1f\n",money[k]);
    }
    return 0;
}