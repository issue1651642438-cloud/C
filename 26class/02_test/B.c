#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 205


int main()
{
    char s1[MAX],s2[MAX];
    fgets(s1,MAX,stdin);
    s1[strcspn(s1,"\n")]='\0';
    int len1 = strlen(s1);
    fgets(s2,MAX,stdin);
    s2[strcspn(s2,"\n")]='\0';
    int len2 = strlen(s2);

    char* substr;
    char* str;

    if(len1<=len2)
    {
        substr=s1;
        str=s2;
    }else{
        substr=s2;
        str=s1;
    }

    if(strstr(str,substr)==NULL)
    {
        printf("No substring\n");
    }else{
        printf("%s is substring of %s\n",substr,str);
    }
    return 0;
    
}