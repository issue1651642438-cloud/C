#include<stdio.h>

int triangle(int n){
    int p=0,i=0;
    for(p=1;p<=n;p++){
        for(i=1;i<=n-p;i++){
            printf(" ");
        }
        for(i=1;i<=(2*p-1);i++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int n=0;
    while(scanf("%d",&n)==1){
        triangle(n);
    }
    return 0;
}