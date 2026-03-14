#include <stdio.h>
#define MOD 10000
#define PERIOD 150000  // 模10000的Pisano周期

// 计算F(n) mod MOD，n不超过PERIOD
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    long long n;
    while (1) {
        scanf("%lld", &n);
        if (n == -1) break;
        // 利用周期简化n，再计算
        int m = n % PERIOD;
        printf("%d\n", fib(m));
    }
    return 0;
}