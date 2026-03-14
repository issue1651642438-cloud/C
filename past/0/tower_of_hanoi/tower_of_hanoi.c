#include<stdio.h>
char tower[3];
int n=0;
void hanno(int n,int i,int j,int k)
{
    char a=tower[i];
    char b=tower[j];
    char c=tower[k];
    if(n==1)
    {
        printf("%c->%d->%c\n",a,n,b);
    }else if(n>=2)
    {
        hanno(n-1,i,k,j);
        printf("%c->%d->%c\n",a,n,b);
        hanno(n-1,k,j,i);
    }
}

int main()
{
    scanf("%d %c %c %c",&n,&tower[0],&tower[1],&tower[2]);
    hanno(n,0,1,2);
}