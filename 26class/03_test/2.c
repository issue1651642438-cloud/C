#include<stdio.h>
#define MAX 2005

void del(int* a,int index,int* number)
{
    for(int i=index;i<(*number);i++)
    {
        a[i] = a[i+1];
    }
    (*number)--;
}

int main()
{
    int c,n,x,a[MAX];
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d%d",&n,&x);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]>x)
            {
                del(a,i,&n);
                i--;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=0) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
}