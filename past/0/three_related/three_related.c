#include<stdio.h>
int main(){
    int a=0;
    scanf("%d",&a);

    if(a%3==0){
        printf("TRUE");
    }else if(a/10==3){
        printf("TRUE");
    }else if(a%10==3){
        printf("TRUE");
    }else{
        printf("FALSE");
    }

    return 0;
}