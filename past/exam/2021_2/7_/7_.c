#include<stdio.h>
#include<string.h>

int m,q;
char n[1005],p[1005];

void chufa(int ln)
{
    q=0;
    int idex=0;
    for(int i=0;i<ln;i++)
    {
        q=q*10+n[i]-'0';
        int current=q/m;
        q=q%m;
        if(!(idex==0&&current==0))
        {
            p[idex++]=current+'0';
        }
    }
    p[idex]='\0';
}

int main()
{
   scanf("%s",n);
   int lenn=strlen(n);

   scanf("%d",&m);

   chufa(lenn);

   printf("%s %d",p,q);

   return 0;
}