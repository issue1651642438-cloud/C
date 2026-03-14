#include<stdio.h>
#include<stdlib.h>

int a[1000][11][11];

void istrigle(int i,int n)
{
    int idex=1;
    for(int j=1;j<n;j++)
    {
        for(int k=0;k<j;k++)
        {
            if(a[i][j][k]!=0)
            {
                idex=0;
                break;
            }            
        }
        if(idex==0)
        {
            break;
        }
    }
    if(idex)
    {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}

int main()
{
    int n=0;
    int number[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
        for(int j=0;j<number[i];j++)
        {
            for(int k=0;k<number[i];k++)
            {
                scanf("%d",&a[i][j][k]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        istrigle(i,number[i]);
    }

    return 0;
}