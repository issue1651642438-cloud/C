#include<stdio.h>
#include<stdlib.h>
#define MAX 20005
int cmp(const void*a,const void*b)
{
    return *(long long*)b-*(long long*)a;
}

int main()
{
    int n;
    long long b;
    long long h[MAX];
    scanf("%d%lld",&n,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&h[i]);
    }
    qsort(h,n,sizeof(long long),cmp);
    int i=0;long long total=0;
    while(total<b){
        total+=h[i];
        i++;
    }
    printf("%d",i);
}