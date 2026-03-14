#include<stdio.h>
int main()
{
    int score[101];
    int idex=0;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&score[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(score[i]>score[idex])
        {
            idex=i;
        }
    }
    printf("%d",idex+1);
    return 0;
}