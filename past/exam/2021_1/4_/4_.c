#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char right[2005];
    char answer[1005][2005];
    int n,m,sum[1005]={0};
    scanf("%d %d",&n,&m);
    getchar();
    fgets(right,2005,stdin);

    for(int i=0;i<m;i++)
    {
        fgets(answer[i],2005,stdin);
        for(int j=0;j<2*n-1;j+=2)
        {
            if(right[j]==answer[i][j])
            {
                sum[i]++;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        printf("%d\n",sum[i]);
    }
    return 0;
}