#include<stdio.h>
#include<string.h>
#define MAX 20005
int main()
{
    int n;
    char s[MAX],t[MAX],line[2*MAX];
    int output[MAX];
    char *p;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s%s",s,t);
        p = strstr(s,t);
        if(p==NULL)
        {
            output[i] = -1;
        }else{
            output[i] = (p-s)/sizeof(char);
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\n",output[i]);
    }
}