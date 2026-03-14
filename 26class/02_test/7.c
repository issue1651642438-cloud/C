#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 25
#define MAXLINE 85
#define MAXSTR 405

int matrix[MAX][MAX] = {0};

void turnTwo(char c,int* str)
{
    int num = 0 ;
    if(c>='A' && c<='Z') num = c-'A'+1;
    for(int i=4;i>=0;i--)
    {
        str[i] = num%2;
        num/=2;
    }
}
int visited[MAX][MAX]={0};
void fillMatrix(int R,int C,int* str,int totalLen)
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int dIndex = 0,curX=0,curY=0;
    for(int i=0;i<R*C;i++)
    {
        matrix[curX][curY] =(i<totalLen)? str[i] : 0;
        visited[curX][curY] = 1;
        if (i == R * C - 1) break;
        int nx = curX+dx[dIndex], ny = curY+dy[dIndex];
        if(nx>=R || nx<0 || ny>=C || ny<0 || visited[nx][ny]==1)
        {
            dIndex = (dIndex+1)%4;
            nx = curX+dx[dIndex]; 
            ny = curY+dy[dIndex];
        }
        curX =nx;
        curY =ny;
    }
}

int main()
{
    int r,c=0;
    char line[MAXLINE];
    int str[MAXSTR];
    memset(str, 0, sizeof(str));

    // 记录str
    scanf("%d %d", &r, &c);     // 读取R和C
    getchar();                  // 吃掉C后面的那个空格或换行
    fgets(line, MAXLINE, stdin); // 读取整行字符串
    int len = strlen(line);
    int* start = str;
    for(int i=0;i<len;i++)
    {
        turnTwo(line[i],start);
        start+=5;
    }

    fillMatrix(r,c,str,len*5);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d",matrix[i][j]);
        }
    }
}