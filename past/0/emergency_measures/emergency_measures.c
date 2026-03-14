#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char* p)
{
    int len=strlen(p);
    for(int i=0;i<len;i++)
    {
        if(p[i]>='a'&&p[i]<='z')
        {
            p[i]=p[i]+'A'-'a';
        }else if(p[i]<='Z'&&p[i]>='A')
        {
            p[i]=p[i]+'a'-'A';
        }
    }
}



int main()
{
    //freopen("emergency_measures.txt","r",stdin);
    int n=0;
    char email0[50];

    fgets(email0,50,stdin);
    int len_email0=strlen(email0);
    email0[len_email0-1]='\0';

    scanf("%d",&n);
    getchar();

    char name[n][50],password[n][50],email[n][50];
    for(int i=0;i<n;i++)
    {
        scanf("%s",name[i]);
        getchar();
        scanf("%s",password[i]);
        getchar();
        scanf("%s",email[i]);
        getchar();
    }

    int isprint=0;
    for(int i=0;i<n;i++)
    {
        int is=strcmp(email0,email[i]);
        if(is==0)
        {
            isprint=1;
            change(password[i]);
            printf("%s %s\n",name[i],password[i]);
        }
    }
    if(!isprint) printf("empty\n");
    return 0;
}