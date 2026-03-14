#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void maxstr(char *p,int plen,char *q,int qlen)
{
    int maxlen=0;
    for(int i=0;i<plen;i++)
    {
        for(int j=i+1;j<=plen;j++)
        {   if(j-i>qlen){
                break;
            }
            char* com=(char*)malloc(sizeof(char)*(j-i+1));
            com=strncpy(com,p+i,j-i);
            com[j-i]='\0';
            char* find2=strstr(q,com);
            if((find2!=NULL)&&j-i>maxlen)
            {
                maxlen=j-i;
            }
            free(com);
        }
    }
    printf("%d\n",maxlen);
}


int main()
{
    freopen("genetic_test.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    char a[n][2][20];
    int len[n][2];
    for(int i=0;i<n;i++)
    {
        scanf("%19s",a[i][0]);
        scanf("%19s",a[i][1]);
        len[i][0]=strlen(a[i][0]);
        len[i][1]=strlen(a[i][1]);
    }
    for(int i=0;i<n;i++)
    {
        maxstr(&a[i][0][0],len[i][0],&a[i][1][0],len[i][1]);
    }
    return 0;
}