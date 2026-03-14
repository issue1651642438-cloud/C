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
    int b=14,t=7,n;
    scanf("%d",&n);
    getchar();
    char string[n][100];
    int len[n];
    for(int i=0;i<n;i++){
        fgets(string[i],100,stdin);
        len[i]=strlen(string[i]);
        string[i][len[i]-1]='\0';
        len[i]--;
    }

    int num0=decnum(&string[0][0],b,len[0]);
    t_num(num0,t);
    if(n>=2){
        for(int i=1;i<n;i++){
            printf(" ");
            int num=decnum(&string[i][0],b,len[i]);
            t_num(num,t);
        }
    }

    return 0;
}