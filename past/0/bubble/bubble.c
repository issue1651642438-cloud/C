#include<stdio.h>
int main()
{
    int a[10],noswap,temp,i,j;
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }

    for(j=0;j<=8;j++){
        if(a[j+1]<a[j]){
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
    }


    for(i=0;i<9;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);
    return 0;
}