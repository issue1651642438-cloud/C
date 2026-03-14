#include<stdio.h>
#include<stdlib.h>

#define MAX_USER 100

int main(){
    //freopen("focusMan.txt","r",stdin);
    int N;
    scanf("%d",&N);

    int mention_count[MAX_USER]={0};
    int *mentioners[MAX_USER];
    int mentioner_count[MAX_USER]={0};

    for(int i=0;i<MAX_USER;i++){
        mentioners[i]=(int *)malloc(N*sizeof(int));
    }


    for(int i=0;i<N;i++){
        int sender,k;
        scanf("%d %d",&sender,&k);

        for(int j=0;j<k;j++){
            int mentioned;
            scanf("%d",&mentioned);

            mention_count[mentioned]++;
            int isduplicate=0;
            for(int m=0;m<mentioner_count[mentioned];m++){
                if(mentioners[mentioned][m]==sender){
                    isduplicate=1;
                    break;
                }
            }
            if(!isduplicate){
                mentioners[mentioned][mentioner_count[mentioned]++]=sender;
            }
        }
    }


    int max_mentioned=0;
    int max_count=0;
    for(int i=1;i<MAX_USER;i++){
        if(mention_count[i]>max_count){
            max_count=mention_count[i];
            max_mentioned=i;
        }
    }


    for(int i=0;i<mentioner_count[max_mentioned];i++){
        for(int j=i+1;j<mentioner_count[max_mentioned];j++){
            if(mentioners[max_mentioned][i]>mentioners[max_mentioned][j]){
                int temp=mentioners[max_mentioned][i];
                mentioners[max_mentioned][i]=mentioners[max_mentioned][j];
                mentioners[max_mentioned][j]=temp;
            }
        }
    }


    printf("%d\n",max_mentioned);
    for(int i=0;i<mentioner_count[max_mentioned];i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",mentioners[max_mentioned][i]);
    }
    printf("\n");


    for(int i=0;i<MAX_USER;i++){
        free(mentioners[i]);
    }

    return 0;
}