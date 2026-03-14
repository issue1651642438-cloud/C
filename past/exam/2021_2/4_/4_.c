#include<stdio.h>
#include<string.h>

int main()
{
    char string[1000];
    int idex=1;
    fgets(string,sizeof(string),stdin);
    int i=0;
    while(string[i]!='\0')
    {
        if(string[i]==' ')
        {
            idex++;
        }
        i++;
    }
    printf("%d",idex);
    return 0;
}