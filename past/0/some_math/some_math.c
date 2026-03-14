#include<stdio.h>
#include<math.h>
int main(){
    double result=(3.21*pow(10,-8)+2.31*pow(10,-7))/(7.16*pow(10,6)+2.01*pow(10,8));
    printf("%.5e\n",result);
    return 0;
}