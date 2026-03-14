#include<stdio.h>

int f(int m,int n)
{
    int k=0;
    if(m==0){
        k=1;
    }else if(n==0){
        k=0;
    }else if(m<n){
        k=f(m,m);
    }
    else{
        k=f(m,n-1)+f(m-n,n);
    }
    return k;
}

int main()
{
    int t;
    scanf("%d",&t);
    int m[t],n[t];
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&m[i],&n[i]);
    }
    for(int i=0;i<t;i++)
    {
        int k=f(m[i],n[i]);
        printf("%d\n",k);
    }
    return 0;
}