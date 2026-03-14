#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(int *)b-*(int *)a;
}

int iswin(int *a,int *b,int *lefta,int*righta,int *leftb,int* rightb)
{
    if(a[*lefta]>b[*leftb])
    {
        (*lefta)++;(*leftb)++;
        return 200;
    }else if(a[*lefta]<b[*leftb])
    {
        (*leftb)++;(*righta)--;
        return -200;
    }else if(a[*righta]<=b[*rightb])
    {
        (*leftb)++;(*righta)--;
        return 0;
    }else
    {
        (*lefta)--;(*leftb)--;
        return -200;
    }
}

int totalwin(int *a,int*b,int n)
{
    int lefta=0,righta=n-1,sum=0,leftb=0,rightb=n-1;
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    while(lefta<=righta)
    {
        sum+=iswin(a,b,&lefta,&righta,&leftb,&rightb);
    }
    return sum;
}

int main()
{
    int sum[100],count=0;
    while(1)
    {
        int n=0;
        scanf("%d",&n);
        if(n==0) break;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        sum[count++]=totalwin(a,b,n);
    }
    for(int i=0;i<count;i++)
    {
        printf("%d\n",sum[i]);
    }
    return 0;
}