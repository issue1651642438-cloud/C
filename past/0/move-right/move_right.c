#include<stdio.h>
int main()
{
    int n,i,move;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&move);
    for(i=n-move;i<n;i++){
        printf("%d ",a[i]);
    }
    for(i=0;i<n-move-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[n-move-1]);
    return 0;
}