#include<stdio.h>
int isOk(int (*color)[100],int i,int j)
{
    if(color[i+1][j]-color[i][j]<50) return 1;
    if(color[i-1][j]-color[i][j]<50) return 1;
    if(color[i][j+1]-color[i][j]<50) return 1;
    if(color[i][j-1]-color[i][j]<50) return 1;
    return 0;
}

int main()
{
    int num,color[100][100],errorCeilNum=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            scanf("%d",&color[i][j]);
        }
    }

    for(int i=1;i<num-1;i++)
    {
        for(int j=1;j<num-1;j++)
        {
            if(isOk(color,i,j)==0)errorCeilNum++;
        }
    }
    printf("%d",errorCeilNum);
}