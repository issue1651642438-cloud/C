#include<stdio.h>
#include<math.h>
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int remain,eaten;
    eaten=y/x;
    if(y%x!=0){
        eaten++;
    }
    remain=n-eaten;

    if(remain<=0){
        remain=0;
    }
    printf("%d",remain);
    return 0;
}