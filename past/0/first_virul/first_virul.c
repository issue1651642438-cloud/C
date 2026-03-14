#include<stdio.h>
#include<math.h>
int main(){
    int patient,death;
    scanf("%d%d",&patient,&death);
    double death_rate=(double)death*100/patient;
    printf("%.3f%%",death_rate);
    return 0;

}