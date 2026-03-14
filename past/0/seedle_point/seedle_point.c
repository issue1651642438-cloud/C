#include<stdio.h>
int main()
{
    //freopen("seedle_point.txt","r",stdin);
    int a[5][5],max[5],ismin[5]={1,1,1,1,1};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<5;i++){
        max[i]=0;
        for(int j=0;j<5;j++){
            if(a[i][max[i]]<a[i][j]) max[i]=j;
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][max[i]]>a[j][max[i]]) ismin[i]=0;
        }
    }

    if(ismin[0]+ismin[1]+ismin[2]+ismin[3]+ismin[4]==0){
        printf("not found");
    }else{
        for(int i=0;i<5;i++){
            if(ismin[i]==1){
                printf("%d %d %d\n",i+1,1+max[i],a[i][max[i]]);
            }
        }
    }
    return 0;
}