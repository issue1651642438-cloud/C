#include<stdio.h>
#include<string.h>

int findMax(char* str)
{
    int max=0,i=0;
    while(str[i]!='\0')
    {
        if(str[max]<str[i]) max=i;
        i++;
    }
    return max;
}

int main()
{
    char line[25],str[15],substr[5];
    while(scanf("%s%s",str,substr)==2)
    {
        int maxIndex=findMax(str);
        maxIndex++;
        strcpy(line,str);
        strcpy(&line[maxIndex],substr);
        strcat(line,&str[maxIndex]);

        printf("%s\n",line);
    }
    
}