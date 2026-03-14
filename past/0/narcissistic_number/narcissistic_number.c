#include<stdio.h>
#include<math.h>
int main(){
    int i,n[3],n0;
    for (i=100;i<1000;i++){
        n[1]=i/100;
        n[2]=(i%100)/10;
        n[3]=i%10;
        n0=powl(n[1],3)+powl(n[2],3)+powl(n[3],3);
        if(n0==i) printf("%d\n",i);
    }
    return 0;
}