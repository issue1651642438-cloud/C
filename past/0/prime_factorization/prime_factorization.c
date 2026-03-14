#include<stdio.h>
#include<malloc.h>
#include<math.h>
void prime_factorization(long n){
    printf("%ld=",n);

    if(n==1){
        printf("1\n");
        return;
    }
    if(n==2){
        printf("2\n");
        return;
    }

    int nsqrt=(int)sqrt(n),i,isfirst=1;
    for(i=2;i<=nsqrt;i++){
        if(n%i==0){
            printf("%d",i);
            n/=(long)i;
            isfirst=0;
            break;
        }
    }
    i=2;
    while((long)i*(long)i<=n){
        while(1){
            if(n%i==0){
                printf("*%d",i);
                n/=(long)i;
            }else{
                break;
            }
        }
        i++;
    }

    if(n>1){
        if(isfirst){
            printf("%ld",n);
        }else{
            printf("*%ld",n);
        }
        
    }


    printf("\n");
}


int main(){
    long n;
    scanf("%ld",&n);
    long *p;
    p=(long*)malloc(n*sizeof(long));
    for(int i=0;i<n;i++){
        scanf("%ld",&p[i]);
    }
    for(int i=0;i<n;i++){
        prime_factorization(p[i]);
        
    }
    free(p);
    return 0;
}