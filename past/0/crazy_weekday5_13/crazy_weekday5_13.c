#include<stdio.h>
#include<math.h>
int days(int month0,int day0,int month,int day){
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days0,days,sum_months0=0,sum_months=0,i;
    for(i=0;i<month0-1;i++){
        sum_months0+=months[i];
    }
    for(i=0;i<month-1;i++){
        sum_months+=months[i];
    }
    days0=sum_months0+day0;
    days=sum_months+day;
    return days-days0;
}
int main(){
    int w;
    scanf("%d",&w);
    int delta_days13[12],i;
    for(i=0;i<12;i++){
        delta_days13[i]=days(1,1,i+1,13);
        if((delta_days13[i]+w-5)%7==0){
            printf("%d\n",i+1);
        }
    }
    return 0;
    
}