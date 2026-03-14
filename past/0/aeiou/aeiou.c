#include<stdio.h>
#include<string.h>
int main()
{
    char string[85];
    fgets(string,85,stdin);
    int sum[]={0,0,0,0,0};
    int i=0;
    while(string[i]!='\0'&&i<85){
        if(string[i]=='a') sum[0]++;
        if(string[i]=='e') sum[1]++;
        if(string[i]=='i') sum[2]++;
        if(string[i]=='o') sum[3]++;
        if(string[i]=='u') sum[4]++;
        i++;
    }
    for(i=0;i<4;i++){
        printf("%d ",sum[i]);
    }
    printf("%d",sum[4]);
    return 0;
}