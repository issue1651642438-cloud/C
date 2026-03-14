#include<stdio.h>
int main()
{
    int n,i,i_;
    scanf("%d",&n);
    int a;
    int light[n];
    for(i=0;i<n;i++)
    {
        light[i]=0;
    }
    for(i=1;i<n;i++)
    {
        for(i_=1;i_<=n;i_++){
            if(i_%(i+1)==0){
                light[i_-1]=1-light[i_-1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(light[i]==1){
            printf("%d ",i+1);
        }
    }
    return 0;
}