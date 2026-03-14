#include<stdio.h>
#define MAX 200
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int n;
    int beginM[MAX],beginD[MAX],overM[MAX],overD[MAX];
    int totalMonth[12]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&beginM[i],&beginD[i],&overM[i],&overD[i]);
        if(beginM[i]==overM[i])
        {
            if(beginD[i]==overD[i])
                totalMonth[beginM[i]-1] += 1;
            else
                totalMonth[beginM[i]-1] += overD[i] - beginD[i];
        }else{
            int j=beginM[i];
            totalMonth[j-1] += month[j-1] - beginD[i] + 1;  // 起始月含进店日
            j++;
            while(j<overM[i]){
                totalMonth[j-1] += month[j-1];
                j++;
            }
            totalMonth[j-1] += overD[i]-1;  // 末月含离店日
        }
    }
    for(int i=0;i<12;i++)
    {
        printf("%d %d\n",i+1,totalMonth[i]);
    }
    return 0;
}