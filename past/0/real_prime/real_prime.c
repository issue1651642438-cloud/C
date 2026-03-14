#include<stdio.h>
#include<math.h>
#include<malloc.h>
int reverse(int n){
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}



int isprime(int p){
    int isprime=1;
    for(int i=2;i*i<=p;i++){
        if(p%i==0){
            isprime=0;
            break;
        }
    }
    if(isprime==1){
        int rev=reverse(p);
        for(int i=2;i*i<=rev;i++){
            if(rev%i==0){
                isprime=0;
                break;
            }
        }
    }
    return isprime;
}



int main(){
    int m,n,true_prime[1000],true_num=0;
    scanf("%d %d",&m,&n);

    for(int i=m;i<=n;i++){
        if(isprime(i)){
            true_prime[true_num++]=i;
        }
    }

    if(true_num==0){
        printf("No");
    }else if(true_num==1){
        printf("%d",true_prime[0]);
    }else{
        printf("%d",true_prime[0]);
        for(int i=1;i<true_num;i++){
            printf(",%d",true_prime[i]);
        }
    }

    return 0;
}


