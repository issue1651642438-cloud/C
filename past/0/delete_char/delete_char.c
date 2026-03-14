#include<stdio.h>
#include<string.h>
int main()
{
    int sum=0,i=0,j=0;
    char s[101],a[101],c;
    fgets(s,101,stdin);
    scanf("%c",&c);
    for( i=0;s[i]!='\0';i++){
        if(s[i]!=c){
            a[j++]=s[i];
        }else{
            sum++;
        }
    }
    a[j]='\0';
    printf("%d\n",sum);
    printf("%s",a);
    return 0;
}