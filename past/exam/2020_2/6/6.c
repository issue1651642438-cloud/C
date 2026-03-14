#include<stdio.h>
#include<string.h>

int a[1001][1001];
// 标记需要置0的行和列（1表示需要置0）
int row_zero[1001] = {0};
int col_zero[1001] = {0};

int main()
{
    int num = 0;
    scanf("%d", &num);

    // 第一步：读取矩阵
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &a[i][j]);
            // 第二步：标记需要置0的行和列（只标记一次）
            if (a[i][j] == 0)
            {
                row_zero[i] = 1;
                col_zero[j] = 1;
            }
        }
    }

    // 第三步：批量置0（先置0行，再置0列）
    for (int i = 0; i < num; i++)
    {
        // 如果当前行需要置0，整行置0
        if (row_zero[i] == 1)
        {
            for (int j = 0; j < num; j++)
            {
                a[i][j] = 0;
            }
        }
        // 如果当前列需要置0，整列置0
        if (col_zero[i] == 1)
        {
            for (int j = 0; j < num; j++)
            {
                a[j][i] = 0;
            }
        }
    }

    // 第四步：输出结果
    for (int i = 0; i < num; i++)
    {
        printf("%d", a[i][0]);
        for (int j = 1; j < num; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}