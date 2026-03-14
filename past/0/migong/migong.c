#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 16

char map[100][MAX][MAX];
int visited[100][MAX][MAX];

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/**
 * DFS搜索函数：从(x,y)出发，探索是否能到达终点(n-1,n-1)
 * @param x 当前列坐标
 * @param y 当前列坐标
 * @param n 迷宫边长
 * @param i 第i个迷宫
 * @return 1: 找到路径, 0: 未找到路劲
 */
int dfs(int x,int y,int n,int i)
{
    if(x==n-1&&y==n-1)
    {
        return 1;
    }
    for(int j=0;j<4;j++)
    {
        int a=x+dir[j][0];
        int b=y+dir[j][1];
        if(a<0||a>n-1||b<0||b>n-1) continue;
        if(map[i][a][b]=='#'||visited[i][a][b]==1) continue;
        visited[i][a][b]=1;
        if(dfs(a,b,n,i)){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int m;
    scanf("%d",&m);
    int n[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&n[i]);
        for(int j=0;j<n[i];j++)
        {
            scanf("%s",map[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        memset(visited[i],0,sizeof(visited[i]));
        visited[i][0][0]=1;
        if(dfs(0,0,n[i],i)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}