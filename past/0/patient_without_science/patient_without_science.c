#include<stdio.h>
int prime(long n);
int _sqrt(long n);
int thirteen(long n);
int main()
{
    //freopen("patient_without_science.txt","r",stdin);
    long m,n,count=0;
    scanf("%ld%ld",&m,&n);
    for(long i=m;i<=n;i++){
        if(prime(i)==1&&_sqrt(i)==1&&thirteen(i)==0){
            count++;
        }
    }
    printf("%ld",count);
}


int prime(long n){
    int isprime=1;
    n/=1000000;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            isprime=0;
            break;
        }
    }
    return isprime;
}


int _sqrt(long n){
    int issqrt=0;
    n=n%1000;
    for(int i=1;i*i<=n;i++){
        if(i*i==n){
            issqrt=1;
        break;
        }
    }
    return issqrt;
}


int thirteen(long n)
{   int isthir=0;
    while(n>=10){
        if(n%100==13){
            isthir=1;
            break;
        }
        n/=10;
    }
    return isthir;
}