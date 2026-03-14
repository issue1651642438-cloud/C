#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 101

typedef struct {
    int x;
    int y;
    int step;
}Queue;
Queue q[10000];

bool visited[101][101]={false};
char map[MAX][MAX];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

/**
 * BFS: 广度搜索算法
 * @param x0:行位置
 * @param y0:列位置
 */
int bfs(int x0,int y0)
{
    int front=0;
    int rear=0;
    q[rear].x=x0;
    q[rear].y=y0;
    q[rear].step=0;
    
    rear++;
    visited[x0][y0]=true;

    while (front<rear)
    {
        Queue curr=q[front];
        front++;

        if(map[curr.x][curr.y]=='T')
        {
            return curr.step;
        }

        for(int i=0;i<4;i++)
        {
            int a=curr.x+dir[i][0];
            int b=curr.y+dir[i][1];

            if(a>=0&&a<n&&b>=0&&b<n
                &&map[a][b]!='#'&&!visited[a][b]){
                    visited[a][b]=true;
                    q[rear].x=a;
                    q[rear].y=b;
                    q[rear].step=curr.step+1;
                    rear++;
                }
        }
    }
    return -1;
}

int main()
{
    int x0,y0;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%s",map[i]);
        for(int j=0;j<n;j++)
        {
            if(map[i][j]=='S')
            {
                x0=i;
                y0=j;
            }
        }
    }

    int min=bfs(x0,y0);
    printf("%d\n",min);

    return 0;
}