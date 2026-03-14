#include<stdio.h>
int main()
{
    int book,n[26]={0};
    scanf("%d",&book);
    int inform[book],maxaut=0;
    char authors[book][27];
    for(int i=0;i<book;i++){
        scanf("%d %s",&inform[i],&authors[i]);
    }
    for(int i=0;i<book;i++){
        int j=0;
        while(authors[i][j]!='\0'){
            int aut=authors[i][j]-'A';
            n[aut]++;
            j++;
        }
    }
    for(int i=0;i<26;i++){
        if(n[i]>n[maxaut]) maxaut=i;
    }

    printf("%c\n%d\n",'A'+maxaut,n[maxaut]);

    for(int i=0;i<book;i++){
        int j=0;
        while(authors[i][j]!='\0'){
            if(authors[i][j]=='A'+maxaut){
                printf("%d\n",inform[i]);
                break;
            }
            j++;
        }
    }
    return 0;

}