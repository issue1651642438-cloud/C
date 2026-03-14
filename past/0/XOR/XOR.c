#include<stdio.h>
#include<string.h>
int main ()
{
    char a[100],b[100],c[100];
    fgets(a,100,stdin);
    fgets(b,100,stdin);
    int i=0;
    for(i=0;a[i]!='\0';i++){
        if(a[i]==b[i]){
            c[i]='0';
        }else{
            c[i]='1';
        }
    }
    c[i-1]='\0';
    printf("%s",c);
    return 0;
}