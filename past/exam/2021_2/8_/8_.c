#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int tag;
    bool idex;
}pos;

pos stand[257];

void todo(int tag0,int group)
{
    if(!(stand[group].idex))
    {
        printf("init\n");
        stand[group].tag=tag0;
        stand[group].idex=true;
    }else if(stand[group].tag==tag0)
    {
        printf("hit\n");
    }else{
        printf("miss\n");
        stand[group].tag=tag0;
        printf("evict\n");
    }
}

int main()
{
    for(int i=0;i<257;i++)
    {
        stand[i].idex=false;
    }

    int n;
    scanf("%d",&n);
    getchar();
    char str[n][15];

    for(int i=0;i<n;i++)
    {
        fgets(str[i],sizeof(str[i]),stdin);
    }

    for(int i=0;i<n;i++)
    {
        int group=0;        
         if(str[i][6]<='9'&&str[i][6]>='0')
        {
            group+=str[i][6]-'0';
        }else{
            group+=str[i][6]-'a'+10;
        }
        group*=16;
        if(str[i][7]<='9'&&str[i][7]>='0')
        {
            group+=str[i][7]-'0';
        }else{
            group+=str[i][7]-'a'+10;
        }

        int tag0=0;
        for(int j=2;j<=5;j++)
        {
            if(str[i][j]<='9'&&str[i][j]>='0')
            {
                tag0+=str[i][j]-'0';
            }else{
                tag0+=str[i][j]-'a'+10;
            }
            tag0*=16;
        }tag0/=16;

        todo(tag0,group);
    }
    return 0;
}