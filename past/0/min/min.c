#include<stdio.h>
int main(){
    int a,b,c,min0,min;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b){
        min0=a;
    }else {
        min0=b;
    }
    if(min0<c){
        min=min0;
    }else{
        min=c;
    }
    printf("%d",min);
    return 0;
}