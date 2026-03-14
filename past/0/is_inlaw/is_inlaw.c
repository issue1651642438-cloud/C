#include<stdio.h>
#include<string.h>
int main(){
    int isinlaw=1;
    int n=0;
    scanf("%d",&n);
    getchar();
    char s[n][85];
    for(int i=0;i<n;i++){
        fgets(s[i],85,stdin);
    }

    for(int i=0;i<n;i++){
        isinlaw=1;
        if(s[i][0]=='_'||(s[i][0]<='z'&&s[i][0]>='a')||(s[i][0]<='Z'&&s[i][0]>='A')){

            for(int j=1;s[i][j]!='\n';j++){
                if (s[i][j]=='_'||(s[i][j]<='z'&&s[i][j]>='a')||(s[i][j]<='Z'&&s[i][j]>='A')||(s[i][j]<='9'&&s[i][j]>='0')){
                    continue;
                }else{
                    isinlaw=0;
                    break;
                }
            }

        }else{
            isinlaw=0;
        }
        printf("%d\n",isinlaw);
    }
    return 0;
}