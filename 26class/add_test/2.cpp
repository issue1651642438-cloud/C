#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define MAX 1005
using namespace std;

int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        char str[MAX];
        cin >> str;
        getchar();
        int count[26]={0};
        for(int j=0;str[j]!='\0';j++)
        {
            count[str[j]-'a']++;
        }
        int index=0;
        for(int j=1;j<26;j++)
        {
            if(count[index]<count[j]) index=j;
        }
        printf("%c %d\n",'a'+index,count[index]);
    }
}