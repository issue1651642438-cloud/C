#include<stdio.h>
int main()
{
    double height=0,total_height=0;
    int n=0,i,h0;
    scanf("%d %d",&h0,&n);
    height=(double)h0;
    for(i=0;i<n;i++){
        total_height+=height*1.5;
        height/=2;
    }
    printf("%f,%f",total_height,height);
    return 0;
}