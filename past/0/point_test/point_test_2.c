#include<stdio.h>
#include<malloc.h>
int main()
{
    int len;
    int *num;
    scanf("%d",&len);
    num=(int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        scanf("%d",num+i);
    }
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i;j++){
            if(*(num+j)<*(num+j+1)){
                int temp=num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
            }
        }
    }
    printf("%d\n%d",num[0],num[1]);
    free(num);
    return 0;
}