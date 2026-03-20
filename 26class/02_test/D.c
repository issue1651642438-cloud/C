#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100005
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int number[MAX];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    qsort(number,n,sizeof(int),cmp);
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("%d",number[i]);
        }else{
            if(number[i]!=number[i-1])
            {
                printf(" %d",number[i]);
            }
        }
    }
    return 0;
}