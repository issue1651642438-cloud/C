#include<stdio.h>
#include<string.h>
#include<math.h>
int oppose(int n)
{
    int oppose=0;
    while(n>0){
        oppose=oppose*10+n%10;
        n/=10;
    }

    return oppose;
}

int rerere(int n)
{
    int rere=0;
    if(n==oppose(n)){
        rere=1;
    }else{
        rere=0;
    }
    return rere;
}
int main()
{
    int num ;
    scanf("%d",&num);
    int found=0;
    for(int i=0;i<7;i++){
        int opp=oppose(num);
        int sum=opp+num;
        printf("%d+%d=%d\n",num,opp,sum);
        if(rerere(sum)){
            found=1;
            printf("Y");
            break;
        }
        num=sum;
    }
    if(found==0) printf("N");
    return 0;
}