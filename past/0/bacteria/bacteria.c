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

int main()
{
    int num,i;
    scanf("%d",&num);
    int n0[num],month0[num],day0[num],n[num],month[num],day[num],DAY[num];
    for (i=0;i<num;i++){
        scanf(" %d %d %d %d %d",&month0[i],&day0[i],&n0[i],&month[i],&day[i]);
        DAY[i]=days(month0[i],day0[i],month[i],day[i]);
        n[i]=n0[i]*powl(2,DAY[i]);
    }
    for(i=0;i<num;i++){
        printf("%d\n",n[i]);
    }
    return 0;
}