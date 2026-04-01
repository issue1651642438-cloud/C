#include<stdio.h>

int n,total=0;

void getnum(int in_num,int stack_num,int out_num)
{
    if(out_num==n) 
    {
        total++;
    }

    if(in_num>0){
        getnum(in_num-1,stack_num+1,out_num);
    }
    if(stack_num>0)
    {
        getnum(in_num,stack_num-1,out_num+1);
    }
}

int main()
{
    scanf("%d",&n);
    getnum(n,0,0);
    printf("%d\n",total);
}