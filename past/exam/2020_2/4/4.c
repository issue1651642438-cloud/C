#include<stdio.h>
#include<stdlib.h>

int m[105],n[105]; // m[k]：第k个数组的行数，n[k]：第k个数组的列数
// 修正维度逻辑：b[k][行][列]（k：第几个数组，i：行，j：列）
int b[105][105][105];

void scan(int k)
{
    scanf("%d%d",&m[k],&n[k]);
    // 按行读取：i是行，j是列（符合常规输入习惯）
    for(int i=0;i<m[k];i++)
    {
        for(int j=0;j<n[k];j++)
        {
            // 【修改1】存储为第k个数组的第i行第j列（维度顺序匹配）
            scanf("%d",&b[k][i][j]);
        }
    }
}

void print(int k)
{
    // 需求：转置（原行→新列，原列→新行） + 每行逆序输出
    for(int i=0;i<n[k];i++) // 原列 → 新行
    {
        // 【修改2】访问原数组第i列的最后一行（逆序第一个元素）
        printf("%d",b[k][m[k]-1][i]);
        // 原第i列从倒数第二行到第一行依次输出（逆序）
        for(int j=m[k]-2;j>=0;j--)
        {
            // 【修改3】访问原数组第i列的第j行
            printf(" %d",b[k][j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int num=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scan(i);
    }

    for(int i=0;i<num;i++)
    {
        print(i);
    }
    return 0;
}