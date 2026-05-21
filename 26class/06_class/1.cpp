#include<stdio.h>

int parent[10001];
int depth[10001];

int getDepth(int i){
    if(depth[i]!=-1){
        return depth[i];
    }
    if(parent[i]==-1){
        depth[i] = 0;
        return 0;
    }
    depth[i] = getDepth(parent[i])+1;
    return depth[i];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        depth[i] = -1;
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&parent[i]);
    }
    for(int i = 1;i<=n;i++){
        printf("%d\n",getDepth(i));
    }
    return 0;
}