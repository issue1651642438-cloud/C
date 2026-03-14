#include<stdio.h>
#include<math.h>
#define N 100
int queen[N];
int queue(int n,int k)
{
    int i,j,count=0;
    if(k==n){
        return 1;
    }else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                if(i==queen[j]||abs(queen[j]-i)==abs(j-k))
                {
                    break;
                }
            }
            if(j==k)
            {
                queen[k]=i;
                count+=queue(n,k+1);
            }
        }
    }
    return count;
}




int main()
{
    int n=0;
    scanf("%d",&n);
    int num=queue(n,0);
    printf("%d",num);
    return 0;
}