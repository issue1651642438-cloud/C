#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXTERM 1005
typedef struct{
    int a;
    int n;
}term;

term dterm(term x)
{
    x.a = x.a * x.n;
    if(x.n!=0) x.n --;
    return x;
}

void showTerm(term* x,int n)
{
    for(int i=0;i<n;i++)
    {
        
        if(i!=0)printf(" ");
        if(i!=0&&x[i].a==0&&x[i].n==0)
        {

        }else{
            printf("%d %d",x[i].a,x[i].n);
        }
    }
    printf("\n");
}

int main()
{
    term x[MAXTERM];
    char line[MAXTERM*4];
    while(fgets(line,MAXTERM*4,stdin)!=NULL)
    {
        if (line[0] == '\n' || line[0] == '\0') continue;
        char* p =line;
        int count=0;
        while(1)
        {
            int a,n;
            if(sscanf(p,"%d%d",&a,&n)==2)
            {
                x[count].a = a;
                x[count].n = n;
                count++;

                while(*p==' '||*p=='\t')p++;
                while(*p!=' '&&*p!='\t'&&*p!='\0')p++;
                while(*p==' '||*p=='\t')p++;
                while(*p!=' '&&*p!='\t'&&*p!='\0')p++;
            }else{
                break;
            }
        }
        for(int i=0;i<count;i++)
        {
            x[i]=dterm(x[i]);
        }
        showTerm(x,count);
    }
}