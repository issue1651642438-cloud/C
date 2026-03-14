#include<stdio.h>
#include<math.h>
int main(){
    int year;
    scanf("%d",&year);
    if(year%400==0||(year%4==0&&year%100!=0)){
        printf("Y\n");
    }else{
        printf("N\n");
    }
    return 0;
}