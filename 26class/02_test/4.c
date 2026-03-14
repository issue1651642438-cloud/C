#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

int divide(char* ten)
{
    int reminder = 0;
    int len = strlen(ten);
    for(int i=0;i<len;i++)
    {
        int current = reminder*10+ten[i]-'0';
        reminder = current % 2;
        ten[i] = current / 2 +'0';
    }
    int start = 0;
    while(ten[start]=='0'&&ten[start+1]!='\0')
    {
        start++;
    }
    memmove(ten,ten+start,len-start+1);
    return reminder;
}

int main()
{
    char ten[MAX],two[MAX];
    fgets(ten,MAX,stdin);
    ten[strcspn(ten,"\n")]='\0';

    int twoI=0;
    while(!(strlen(ten)==1&&ten[0]=='0'))
    {
        two[twoI] = divide(ten)+'0';
        twoI ++;
    }
    two[twoI] = '\0';
    
    int len = strlen(two);
    for(int i=0;i<len/2;i++)
    {
        int temp = two[i];
        two[i] = two[len-i-1];
        two[len-i-1] = temp;
    }

    printf("%s",two);
    return 0;
}