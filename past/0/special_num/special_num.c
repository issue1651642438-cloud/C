#include<stdio.h>
int isspecial(int num)
{
    if(num==0) return 0;
    int divisor=1;
    while(num/divisor>=10){
        divisor*=10;
    }

    int i=1;
    while(divisor>0){
        int digit=(num/divisor)%10;
        if((digit%2)!=i%2) return 0;
        divisor/=10;
        i++;
    }
    return 1;
}



void allspecial(int l,int r)
{
    int count=0;
    for(int i=l;i<=r;i++)
    {
        count+=isspecial(i);
    }
    printf("%d\n",count);
}

int main()
{
    freopen("special_num.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int l[n],r[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    for(int i=0;i<n;i++){
        allspecial(l[i],r[i]);
    }
    return 0;
}