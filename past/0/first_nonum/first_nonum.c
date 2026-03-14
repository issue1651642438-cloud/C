#include<stdio.h>
int main()
{
    long int n;
    scanf("%ld",&n);
    long int num[n],NUM[n];

    long int i=0,k=1;
    for(i=0;i<n;i++){
        NUM[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%ld",&num[i]);
        if(num[i]<=n&&num[i]>0){
            NUM[num[i]-1]=num[i];
        }
    }
    for(i=0;i<n;i++){
        if(NUM[i]==0) break;
    }
    printf ("%d",i+1);
    return 0;
}