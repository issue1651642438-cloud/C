#include<stdio.h>
int main()
{
    int year=0,isLunarYear=0;
    scanf("%d",&year);

    if(year%4==0) {isLunarYear=1;}
    if(year%100==0) {isLunarYear=0;}
    if(year%400==0) {isLunarYear=1;}
    if(year%3200==0) {isLunarYear=0;}
    if(isLunarYear) {printf("Y");}
    else {printf("N");}
    return 0;
}