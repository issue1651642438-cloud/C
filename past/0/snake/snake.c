#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[15][15] = {0};  // 初始化n×n数组（n≤15，数组足够大）
    int num = 1;           // 待填充的数字，从1开始

    // 遍历每一层s（s = i+j，范围0~2n-2）
    for (int s = 0; s <= 2 * n - 2; s++) {
        int i_min, i_max;
        // 计算当前层i的最小值（确保j = s-i < n）
        i_min = (s - (n - 1) > 0) ? (s - (n - 1)) : 0;
        // 计算当前层i的最大值（确保i < n且j = s-i ≥0）
        i_max = (s < n - 1) ? s : (n - 1);

        if (s % 2 == 1) {
            // 奇数层：i从i_min到i_max（从上到下填充）
            for (int i = i_min; i <= i_max; i++) {
                int j = s - i;  // j由层号s和i推导
                a[i][j] = num++;
            }
        } else {
            // 偶数层：i从i_max到i_min（从下到上填充）
            for (int i = i_max; i >= i_min; i--) {
                int j = s - i;
                a[i][j] = num++;
            }
        }
    }

    // 输出数组：相邻元素空格分隔，行尾无空格
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                printf("%d\n", a[i][j]);  // 最后一个元素换行
            } else {
                printf("%d ", a[i][j]);   // 中间元素加空格
            }
        }
    }

    return 0;
}