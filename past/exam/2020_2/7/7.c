#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int isprime(int n)
{
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int main()
{
    char a[10];
    int len,num;
    fgets(a,sizeof(a),stdin);
    sscanf(a,"%d%n",&num,&len);
    for(int i=0;i<len;i++)
    {
        if(isprime(num)==0)
        {
            printf("NO\n");
            return 0;
        }
        num/=10;
    }
    printf("YES\n");
    return 0;
}