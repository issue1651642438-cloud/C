#include<stdio.h>
#include<string.h>
int main()
{
    char *foodPairs[11][2]={
        {"potato", "persimmon"},
        {"egg", "glucide"},
        {"onion", "honey"},
        {"bean-curd", "honey"},
        {"radish", "agaric"},
        {"taro", "banana"},
        {"pignut", "cucumber"},
        {"beef", "chestnut"},
        {"rabbit", "celery"},
        {"crab", "persimmon"},
        {"carp", "liquorice"}
    };

    //freopen("nomatch_food.txt","r",stdin);
    int n=0;
    scanf("%d",&n);
    char ispair[n][2][65];
    int isis[n];
    for(int i=0;i<n;i++){
        scanf("%s%s",&ispair[i][0],&ispair[i][1]);
        isis[i]=1;
    }

    for(int i=0;i<n;i++){
        //搜索每一个元素是否等于ispair[i][0];
        for(int j=0;j<11;j++){
            for(int k=0;k<2;k++){
                int i1=strcmp(ispair[i][0],foodPairs[j][k]);
                int i2=strcmp(ispair[i][1],foodPairs[j][1-k]);
                if(i1==0&&i2==0){
                        isis[i]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(isis[i]==0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}