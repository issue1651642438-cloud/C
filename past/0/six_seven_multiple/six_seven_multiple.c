//输出1－100之间能被6或者7整除的所有数的和
#include<stdio.h>
int main(){
    int i=1,sum=0;
    while(i<=100){
        if(i%6==0||i%7==0){
            sum+=i;
        }
        i++;
    }
    printf("%d",sum);
    return 0;
}