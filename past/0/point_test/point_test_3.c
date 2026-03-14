#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main ()
{
    int b;
    char s[]="abc";
    char *p1,*p2,*p3=s;
    b=3;
    p1=(char*)malloc(30);
    p2=(char*)malloc(20);
    strcpy(p1,"1234");
    return 0;
}