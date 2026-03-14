#include <stdio.h>

int n;
int count = 0;

void dfs(int c, int b) {
    int rem = n - 5 * c;
    // 当c超过最大可能值时，返回
    if (5 * c > n) {
        return;
    }
    // 当b超过当前c对应的最大可能值时，递归处理下一个c
    if (2 * b > rem) {
        dfs(c + 1, 0);
        return;
    }
    int a = rem - 2 * b;
    count++;
    printf("%03d%12d%12d%12d\n", count, a, b, c);
    dfs(c, b + 1);
}

int main() {
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}