#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();

    char s[n][85];
    for(int i=0;i<n;i++){
        fgets(s[i],85,stdin);
    }

    for(int i=0;i<n;i++){
        for(int j=0;s[i][j]!='\0';j++){
            if((s[i][j]>='a'&&s[i][j]<='y')||(s[i][j]>='A'&&s[i][j]<='Y')){
                s[i][j]++;
            }else if(s[i][j]=='z'){
                s[i][j]='a';
            }else if(s[i][j]=='Z'){
                s[i][j]='A';
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}