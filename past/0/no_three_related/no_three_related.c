#include<stdio.h>
int main()
{
    int n=0;
    while(scanf("%d",&n)==1){
        int is_related;
        if(n%3==0 || n/10==3 || n%10==3){
            is_related=1;
        }else{
            is_related=0;
        }
        is_related==1 ?printf("TRUE\n"):printf("FALSE\n");
    }

    return 0;
}