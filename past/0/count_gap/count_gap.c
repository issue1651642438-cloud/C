#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void* b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int a[1000],count=1;
    scanf("%d",&a[0]);
    while(scanf(",%d",&a[count])==1)
    {
        count++;
    }
    qsort(a,count,sizeof(int),cmp);

    printf("%d\n%d",count,a[count-1]-a[0]);
    return 0;
}