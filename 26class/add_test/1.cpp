#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 65

int main()
{
    char str[MAX];
    int num[MAX];
    while(fgets(str,MAX,stdin)!=NULL)
    {
        str[strcspn(str,"\n")]='\0';
        int len = strlen(str);
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='0'&&str[i]<='9'){
                num[count++] = str[i]-'0';
            }
        }
        for(int i=0;i<count;i++)
        {
            printf("%4d",num[i]);
        }
        printf("\n");
    }
}