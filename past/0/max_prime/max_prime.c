#include<stdio.h>
#include<math.h>
int maxPrimeFactor(int p){
    int max=1;
    for(int i=2;i*i<=(p);i++){
        while((p)%i==0){
            max=i;
            (p)/=i;
        }
    }
    if(p!=1) max=p;

    return max;
}



int main(){
    int m,n;
    scanf("%d%d",&m,&n);

   printf("%d",maxPrimeFactor(m));
    for(int i=m+1;i<=n;i++){
        printf(",%d",maxPrimeFactor(i));
    }
    return 0;
}