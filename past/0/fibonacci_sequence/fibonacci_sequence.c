#include<stdio.h>
int main()
{
    //构造斐波那契数列a[n]
    int a[20],i;
    a[0]=1;
    a[1]=1;
    for(i=2;i<20;i++){
        a[i]=a[i-1]+a[i-2];
    }
    //构造完毕
    int count;
    scanf("%d",&count);
    int b[count];
    for (i=0;i<count;i++){
        scanf("%d",&b[i]);
    }
    for(i=0;i<count;i++){
        printf("%d\n",a[b[i]-1]);
    }
    return 0;
}