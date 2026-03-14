#include<stdio.h>
int main()
{
    int a[12],b[12],i;
    for(i=0;i<12;i++){
        a[i]=i+1;
        if(i+1==1||i+1==3||i+1==5||i+1==7||i+1==8||i+1==10||i+1==12){
            b[i]=31;
        }else if(i+1==2){
            b[i]=28;
        }else{
            b[i]=30;
        }
            printf("%-18d%d\n",a[i],b[i]);
        
    }
    return 0;
}