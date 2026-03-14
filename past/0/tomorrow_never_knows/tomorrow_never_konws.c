#include<stdio.h>
int main(){
    int year0,month0,day0;
    int year,month,day;
    scanf("%d-%d-%d",&year0,&month0,&day0);
    //下面分闰年and不闰年
    if((year0%4==0&&year0%100!=0)||year0%400==0){
        int months[12]={31,29,31,30,31,30,31,31,30,31,30,31};
        //下面分为月底and不是月底；
        if(day0!=months[month0-1]){
            year=year0;
            month=month0;
            day=day0+1;
        }else if(month0!=12){
            //讨论是不是年末
            year=year0;
            month=month0+1;
            day=1;
        }else{
            year=year0+1;
            month=1;
            day=1;
        }
    }else{
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        //下面分为月底and不是月底；
        if(day0!=months[month0-1]){
            year=year0;
            month=month0;
            day=day0+1;
        }else if(month0!=12){
            //讨论是不是年末
            year=year0;
            month=month0+1;
            day=1;
        }else{
            year=year0+1;
            month=1;
            day=1;
        }
    }
        printf("%d-%02d-%02d",year,month,day);
    return 0;
}