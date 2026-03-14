#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int main()
{
    int n;
    float a[MAX];
    int dp[MAX]; //以第i个同学结尾，能组成的最大长度
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }

    int ans = 1;
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(a[j]>=a[i])
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(dp[i]>ans) ans = dp[i];
    }
    printf("%d",ans);

    return 0;
}
