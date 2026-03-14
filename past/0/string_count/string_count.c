
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int scan(char* line,char* word,int *count)
{
    int isin=0;
    int len_line=strlen(line);
    int len_word=strlen(word);
    char* ptr=strstr(line,word);
    if(ptr==NULL){
        return 0;
    }else{
        char p[len_word];
        for(int i=0;i<len_word;i++){
            p[i]==0;
        }
        strncpy(ptr,p,len_word);
        (*count)++;
        return 1;
    }
}

int main()
{
    //freopen("string_count.txt","r",stdin);
    char a[100],word[100];
    fgets(a,100,stdin);
    getchar();
    fgets(word,100,stdin);
    int len=strlen(a);
    a[len-1]='\0';
    len=strlen(word);
    word[len-1]='\0';
    int count=0;
    int re=0;
    do{
        re=scan(a,word,&count);
    }while(re);
    printf("%d",count);
    return 0;
}