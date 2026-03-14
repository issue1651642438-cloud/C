#include<stdio.h>
#include<string.h>

void permute(char str[],int start,int len)
{
    if(start==len)
    {
        printf("%s\n",str);
        return;
    }
    for(int i=start;i<len;i++)
    {
        char temp=str[start];
        str[start]=str[i];
        str[i]=temp;
        permute(str,start+1,len);
        temp=str[start];
        str[start]=str[i];
        str[i]=temp;
    }
}
int main()
{
    char str[7];
    scanf("%s",str);
    int len=strlen(str);
    permute(str,0,len);
    return 0;
}