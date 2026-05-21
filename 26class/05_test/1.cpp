#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    while(1){
        if(a>b) a = a/2;
        else if (a<b) b = b/2;
        else{
            printf("%d",a);
            return 0;
        }
    }

}