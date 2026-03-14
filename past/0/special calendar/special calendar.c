
#include<stdio.h>
#include<string.h>

// 步骤1：计算输入时间相对于基准（2000-1-1 0:0:0）的常用总秒数
long long calculate_common_total_sec(long long y0, long long m0, long long d0, long long h0, long long min0, long long sec0) {
    long long total_days = 0;
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 1. 计算2000年到y0-1年的总天数（含闰年）
    for (long long y = 2000; y < y0; ++y) {
        total_days += 365;
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            total_days += 1; // 闰年加1天
        }
    }

    // 2. 计算y0年1月到m0-1月的总天数（处理闰年2月）
    int is_leap = ((y0 % 4 == 0 && y0 % 100 != 0) || (y0 % 400 == 0));
    for (int i = 0; i < m0 - 1; ++i) {
        total_days += month_days[i];
        if (is_leap && i == 1) { // 闰年且当前是2月（索引1），加1天
            total_days += 1;
        }
    }

    // 3. 加上当月天数差（d0-1：基准是1月1日，所以减1）
    total_days += (d0 - 1);

    // 4. 转换为总常用秒数
    return total_days * 86400 + h0 * 3600 + min0 * 60 + sec0;
}

// 步骤2：将常用时间转换为特殊日历
void convert_to_special_calendar(long long h0, long long min0, long long sec0, long long y0, long long m0, long long d0) {
    // 1. 计算常用总秒数
    long long common_total_sec = calculate_common_total_sec(y0, m0, d0, h0, min0, sec0);

    // 2. 转换为特殊总秒数（125/108 = 100000/86400）
    long long special_total_sec = (common_total_sec * 125) / 108;

    // 3. 拆分特殊时分秒（1天=10h=100min=100sec=100000sec）
    long long special_total_days = special_total_sec / 100000; // 特殊日历总天数
    long long remaining_sec = special_total_sec % 100000;      // 当天剩余特殊秒数
    long long mhour = remaining_sec / 10000;                   // 特殊小时（0-9）
    long long mmin = (remaining_sec % 10000) / 100;            // 特殊分钟（0-99）
    long long msec = remaining_sec % 100;                      // 特殊秒（0-99）

    // 4. 拆分特殊日期（1000天/年、100天/月、日/月从1开始）
    long long myear = special_total_days / 1000;                // 年从0开始
    long long remaining_days = special_total_days % 1000;
    long long mmonth = (remaining_days / 100) + 1;              // 月从1开始（0→1）
    long long mday = (remaining_days % 100) + 1;                // 日从1开始（0→1）

    // 按要求格式输出
    printf("%lld:%lld:%lld %lld.%lld.%lld\n", mhour, mmin, msec, mday, mmonth, myear);
}

int main() {
    //freopen("special calendar.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    // 存储输入数据（C99支持变长数组，不支持则改为long long h[100]等固定大小）
    long long h[n], min[n], sec[n], d[n], m[n], y[n];

    // 读取每组数据（去掉scanf末尾的\n，避免读取异常）
    for (int i = 0; i < n; ++i) {
        scanf("%lld:%lld:%lld %lld.%lld.%lld", &h[i], &min[i], &sec[i], &d[i], &m[i], &y[i]);
    }

    // 转换并输出每组结果
    for (int i = 0; i < n; ++i) {
        convert_to_special_calendar(h[i], min[i], sec[i], y[i], m[i], d[i]);
    }

    return 0;
}