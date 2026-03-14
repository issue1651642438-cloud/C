#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],k=0,is=1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        is=1;
        for(int j=0;j<i;j++){
            if (a[i]==a[j]) is=0;
        }
        if(is==1){
            b[k++]=a[i];
        }
    }
    for(int j=0;j<k-1;j++){
        printf("%d ",b[j]);
    }
    printf("%d",b[k-1]);
    return 0;
}