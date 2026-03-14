#include<stdio.h>
int main(){
    char x;
    while((getchar()!=EOF)){
        x=getchar();
        printf("%2c  %3d\n",x,x);
    }
    return 0;
}