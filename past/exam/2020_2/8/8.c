#include<stdio.h>
#include<stdlib.h>
#include<math.h> // 用于fabs判断浮点数是否为0

// 修正后的qsort比较函数：符合规范，处理精度问题
int cmp(const void* a, const void* b) {
    float ta = *(float*)a;
    float tb = *(float*)b;
    // 考虑浮点数精度，差值小于1e-6视为相等
    if (fabs(ta - tb) < 1e-6) {
        return 0; // 相等返回0
    }
    return ta > tb ? 1 : -1; // 降序排列
}

int main() {
    int m, n;
    float eat[30], wait[30], sum = 0.0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%f", &eat[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &wait[i]);
    }

    int k = 0;
    // 外层循环：还有等待的人，且当前有可消耗的时间
    while (k < n) {
        // 降序排序，取当前最长的进食时间
        qsort(eat, m, sizeof(float), cmp);
        float current_time = eat[0];
        // 无消耗时间（所有人都吃完），直接替换
        if (fabs(current_time) < 1e-6) {
            // 遍历所有吃完的位置，替换为等待的人
            for (int i = 0; i < m && k < n; i++) {
                if (fabs(eat[i]) < 1e-6) {
                    eat[i] = wait[k];
                    k++;
                }
            }
            continue; // 替换后重新排序
        }

        // 累加当前消耗的时间到总耗时
        sum += current_time;
        // 所有人的进食时间减去当前消耗的时间
        for (int i = 0; i < m; i++) {
            eat[i] -= current_time;
        }

        // 遍历所有吃完的位置（浮点数近似0），替换为等待的人
        for (int i = 0; i < m && k < n; i++) {
            if (fabs(eat[i]) < 1e-6) {
                eat[i] = wait[k];
                k++;
            }
        }
    }

    // 处理最后剩余的进食时间
    qsort(eat, m, sizeof(float), cmp);
    sum += eat[0];

    // 输出保留1位小数
    printf("%.1f\n", sum);
    return 0;
}