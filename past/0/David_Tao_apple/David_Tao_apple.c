#include<stdio.h>
int main()
{
    int h[10],height,i,count=0;
    for(i=0;i<10;i++){
        scanf("%d ",&h[i]);
    }
    scanf("%d",&height);
    for(i=0;i<10;i++){
        if(h[i]<=height+30){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}