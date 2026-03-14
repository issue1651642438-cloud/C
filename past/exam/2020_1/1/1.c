#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char name[10];
    int is,guashou,atm=0;
    scanf("%s%d%d",&name,&is,&guashou);
    if(name[0]=='d')
    {
        atm=1;
        if(is==1)atm=6;
    }else{
        if(name[0]=='a')atm=2;
        if(name[0]=='b')atm=1;
        if(name[0]=='c')atm=3;
        if(is==1)atm+=1;
    }

    if(atm>=guashou)printf("\n");
    else printf("YES\n");

    return 0;
}