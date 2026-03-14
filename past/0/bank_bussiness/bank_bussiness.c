#include<stdio.h>
#include<stdlib.h>
struct custom
{
    int idex;
    int time;
};

int cmp(const void* a,const void* b)
{
    int ta=((struct custom*)a)->time;
    int tb=((struct custom*)b)->time;
    if(ta-tb!=0)
    {
        return ta-tb;
    }else{
        return ((struct custom*)a)->idex-((struct custom*)b)->idex;
    }
}

long double average(struct custom* p,int n)
{
    long long int sum=0;
    long long int total=0;
    for(int i=0;i<n;i++)
    {
        total+=sum;
        sum+=p[i].time;
    }
    return (long double)total/n;
}

int main()
{
    //freopen("bank_bussiness.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    struct custom* p=(struct custom*)malloc(n*sizeof(struct custom));
    for(int i=0;i<n;i++)
    {
        (p+i)->idex=i+1;
        scanf("%d",&(p+i)->time);
    }

    qsort(p,n,sizeof(struct custom),cmp);

    printf("%d",p->idex);
    for(int i=1;i<n;i++)
    {
        printf(" %d",(p+i)->idex);
    }
    printf("\n%.2llf",average(p,n));
    free(p);
    return 0;
}