#include <stdio.h>
#include <string.h>

/**
 * 验证硬币c是否为假币（is_heavy=1表示重，0表示轻），是否符合某次称量结果
 * @param c 待验证的硬币（A-L）
 * @param is_heavy 假币是否为重（1=重，0=轻）
 * @param left 天平左边的硬币字符串
 * @param right 天平右边的硬币字符串
 * @param res 称量结果（even/up/down）
 * @return 符合返回1，否则返回0
 */
int is_valid(char c, int is_heavy, char *left, char *right, char *res) {
    if (strcmp(res, "even") == 0) {
        // 平衡状态：假币不能在左右两侧
        return (strchr(left, c) == NULL) && (strchr(right, c) == NULL);
    } else if (strcmp(res, "up") == 0) {
        // 右端高：左边重（重假币在左）或右边轻（轻假币在右）
        if (is_heavy) {
            return strchr(left, c) != NULL;
        } else {
            return strchr(right, c) != NULL;
        }
    } else if (strcmp(res, "down") == 0) {
        // 右端低：右边重（重假币在右）或左边轻（轻假币在左）
        if (is_heavy) {
            return strchr(right, c) != NULL;
        } else {
            return strchr(left, c) != NULL;
        }
    }
    return 0; // 无效结果（题目保证输入合法）
}

int main() {
    int n;
    scanf("%d", &n); // 读取测试用例数
    
    while (n--) {
        char left[3][10], right[3][10], res[3][10];
        // 读取三次称量结果
        for (int i = 0; i < 3; i++) {
            scanf("%s %s %s", left[i], right[i], res[i]);
        }
        
        // 枚举所有硬币（A-L）和两种轻重状态
        for (char c = 'A'; c <= 'L'; c++) {
            // 验证是否为轻假币
            int valid = 1;
            for (int i = 0; i < 3; i++) {
                if (!is_valid(c, 0, left[i], right[i], res[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                printf("%c is the counterfeit coin and it is light.\n", c);
                continue;
            }
            
            // 验证是否为重假币
            valid = 1;
            for (int i = 0; i < 3; i++) {
                if (!is_valid(c, 1, left[i], right[i], res[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
    
    return 0;
}