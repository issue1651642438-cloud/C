#include<stdio.h>
int main()
{
    int count=10;
    int num[count];
    for(int i=0;i<count;i++)
    {
        scanf("%d",&num[i]);
    }

    int temp=0;
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-1-i;j++)
        {
            if(num[j]>num[j+1])
            {
                temp = num[j+1];
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
    }

    printf("%d %d",num[0],num[1]);
    return 0;
}