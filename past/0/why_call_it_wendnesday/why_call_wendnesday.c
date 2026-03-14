#include<stdio.h>
#include<math.h>
#include<string.h>
int decnum(char *s,int n,int len)
{
    int num=0;
    for(int i=0;i<len;i++){
        int power=1;
        for(int j=0;j<len-1-i;j++){
            power*=n;
        }
        if(s[i]>='A'&&s[i]<='Z'){
            num+=(s[i]-'A'+10)*power;
        }else{
            num+=(s[i]-'0')*power;
        }
    }
    return num;
}



void t_num(int num,int t){
   
    char string[100];
    int i=0;
    while(num!=0){
        if(num%t>=10){
            string[i++]=num%t-10+'A';
        }else{
            string[i++]=num%t+'0';
        }
        num/=t;

    }
    for(int j=i-1;j>=0;j--){
        printf("%c",string[j]);
    }
    
}



int main()
{
    int b,t;
    scanf("%d%d",&b,&t);
    getchar();
    char string[100];
    fgets(string,100,stdin);
    int len=strlen(string);
    string[len-1]='\0';
    len--;
    int num=decnum(&string[0],b,len);
    t_num(num,t);

    return 0;
}