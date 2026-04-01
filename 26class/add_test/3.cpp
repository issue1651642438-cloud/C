#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2000
int main()
{
    int num1=0,num2=0,num3=0,num4=0;
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strcspn(str,"\n")]='\0';
    char* p=str;
    while(1)
    {
        if(*p>='0'&&*p<='9') num1++;
        else if(*p>='a'&&*p<='z') num2++;
        else if(*p>='A'&&*p<='Z') num3++;
        else num4++;

        if(*p=='*') break;

        p++;
    }
    printf("%d\n%d\n%d\n%d\n",num1,num2,num3,num4);
}
