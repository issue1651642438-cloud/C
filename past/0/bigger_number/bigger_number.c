#include<stdio.h>
int main(){
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    if(x==y){
        printf("=\n");
    }else if(x>y){
        printf(">\n");
    }else{
        printf("<\n");
    }
    return 0;
}