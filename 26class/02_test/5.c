#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char key[20];
    int value;
} English;

English word[32]={
    {"negative",-1},{"zero",0},{"one",1},
    {"two",2},{"three",3},{"four",4},
    {"five",5},{"six",6},{"seven",7},
    {"eight",8},{"nine",9},{"ten",10},
    {"eleven",11},{"twelve",12},{"thirteen",13},
    {"fourteen",14},{"fifteen",15},{"sixteen",16},
    {"seventeen",17},{"eighteen",18},{"nineteen",19},
    {"twenty",20},{"thirty",30},{"forty",40},
    {"fifty",50},{"sixty",60},{"seventy",70},
    {"eighty",80},{"ninety",90},{"hundred",100},
    {"thousand",1000},{"million",1000000}
};

// 查找单词对应的值
int findValue(char* w) {
    for(int i = 0; i < 32; i++) {
        if(strcmp(w, word[i].key) == 0)
            return word[i].value;
    }
    return -999; // 找不到
}

// 计算一段数组（不含million/thousand）的值
// 例如 [eight, hundred, fourteen] => 814
int calcSegment(int* a, int len) {
    int result = 0;
    int i = 0;
    while(i < len) {
        if(i+1 < len && a[i+1] == 100) {
            result += a[i] * 100;
            i += 2;
        } else {
            result += a[i];
            i++;
        }
    }
    return result;
}

int main()
{
    char line[200];
    while(fgets(line, 200, stdin)) {
        // 去掉换行
        line[strcspn(line, "\n")] = '\0';
        // 空行结束
        if(strlen(line) == 0) break;

        // 解析单词
        int a[30];
        int count = 0;
        char* token = strtok(line, " ");
        while(token != NULL) {
            a[count++] = findValue(token);
            token = strtok(NULL, " ");
        }

        // 判断负数
        int neg = 0;
        int start = 0;
        if(a[0] == -1) {
            neg = 1;
            start = 1;
        }

        // 找million和thousand的位置
        int milPos = -1, thoPos = -1;
        for(int i = start; i < count; i++) {
            if(a[i] == 1000000) milPos = i;
            if(a[i] == 1000)    thoPos = i;
        }

        long long result = 0;

        if(milPos != -1) {
            // million前面的段
            result += (long long)calcSegment(a + start, milPos - start) * 1000000;
            start = milPos + 1;
        }
        if(thoPos != -1) {
            // thousand前面的段
            result += (long long)calcSegment(a + start, thoPos - start) * 1000;
            start = thoPos + 1;
        }
        // 剩余部分
        result += calcSegment(a + start, count - start);

        if(neg) result = -result;

        printf("%lld\n", result);
    }
    return 0;
}