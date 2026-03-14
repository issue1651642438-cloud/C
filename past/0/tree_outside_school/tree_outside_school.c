#include<stdio.h>
int main()
{
    int l,m,i,j;
    scanf("%d %d",&l,&m);
    int tree[l+1],start[m],over[m];
    for(i=0;i<=l;i++)
    {
        tree[i]=1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&start[i],&over[i]);
        for(j=start[i];j<=over[i];j++)
        {
            tree[j]=0;
        }
    }
    int sum=0;
    for(i=0;i<=l;i++){
        sum+=tree[i];
    }
    printf("%d",sum);
    return 0;
}