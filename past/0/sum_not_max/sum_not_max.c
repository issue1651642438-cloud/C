#include<stdio.h>
int main(){
    //输入数字
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf(" %d",&a[i]);
    }
    //找到最大值
    int max;
    max=a[0];
    for(i=1;i<n;i++){
        if(a[i]>=max){
            max=a[i];
        }
    }
    //加起来
    int sum=0;
    for(i=0;i<n;i++){
        if(a[i]!=max){
            sum+=a[i];
        }
    }
    printf("%d",sum);
    return 0;
}