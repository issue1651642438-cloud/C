#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char secret[105],truth[105];
    fgets(secret,105,stdin);
    fgets(truth,105,stdin);
    secret[strcspn(secret,"\n")] = '\0';
    truth[strcspn(truth,"\n")] = '\0';

    int secretAlpNum[26]={0},secretI=0;
    int truthAlpNum[26]={0},truthI=0;

    while(secret[secretI]!='\0')
    {
        secretAlpNum[secret[secretI]-'A']++;
        secretI++;
    }
    while(truth[truthI]!='\0')
    {
        truthAlpNum[truth[truthI]-'A']++;
        truthI++;
    }

    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25-i;j++)
        {
            if(secretAlpNum[j]>secretAlpNum[j+1])
            {
                int temp = secretAlpNum[j+1];
                secretAlpNum[j+1] = secretAlpNum[j];
                secretAlpNum[j] = temp;
            }
        }
    }
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25-i;j++)
        {
            if(truthAlpNum[j]>truthAlpNum[j+1])
            {
                int temp = truthAlpNum[j+1];
                truthAlpNum[j+1] = truthAlpNum[j];
                truthAlpNum[j] = temp;
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        if(truthAlpNum[i]!=secretAlpNum[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}