#include<iostream>
#include<stdio.h>
using namespace std;

double power(double x, int n){
    if(n == 1) return x;
    if(n == 0) return 1;

    if(n%2==0) return power(x*x, n/2);
    else return x*power(x*x, (n-1)/2);
}

int main(){
    double x;
    int n;
    cin>>x>>n;
    double result;
    if(n==0){
        result = 1;
    }else if(n>0){
        result = power(x,n);
    }else{
        result = 1/power(x,-n);
    }
    printf("%.2lf\n",result);
}