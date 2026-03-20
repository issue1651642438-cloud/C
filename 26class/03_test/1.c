#include<stdio.h>
#define MAX 2005
void reverse(int *num,int len)
{
    int temp=0;
    for(int i=0;i<len/2;i++)
    {
        temp = num[i];
        num[i] = num[len-1-i];
        num[len-1-i] = temp;
    }
    return ;
}

int main()
{
    int c,x,y,n,a[MAX];
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d%d%d",&n,&x,&y);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        reverse(a,n);
        for(int i=0;i<n;i++)
        {
            if(a[i]>x&&a[i]<y)
            {
                printf("%d %d\n",a[i-1],a[i+1]);
                break;
            }
        }
    }
}