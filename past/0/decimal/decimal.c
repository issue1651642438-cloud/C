#include<stdio.h>
#include<string.h>
void dAdd(char a[],char b[],char result[])
{
    int lenA=strlen(a);
    int lenB=strlen(b);
    int maxLen=(lenA>lenB)?lenA:lenB;
    int carry=0;
    int resultIndex=0;

    for(int i=lenA-1,j=lenB-1;i>=0||j>=0;i--,j--)
    {
        int bitA=(i>=0)?(a[i]-'0'):0;
        int bitB=(j>=0)?(b[j]-'0'):0;
        int sum=bitA+bitB+carry;
        result[resultIndex++]=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry==1){
        result[resultIndex++]='1';
    }
    result[resultIndex]='\0';

    for(int i=0;i<resultIndex/2;i++){
        char temp=result[i];
        result[i]=result[resultIndex-1-i];
        result[resultIndex-1-i]=temp;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char a[n][401],b[n][401],result[n][402];
    for(int i=0;i<n;i++){
        scanf("%s %s",a[i],b[i]);
        dAdd(a[i],b[i],result[i]);
    }
    for(int i=0;i<n;i++){
        printf("%s\n",result[i]);
    }

    return 0;
}