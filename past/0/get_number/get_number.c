#include<stdio.h>
#include<string.h>
int main()
{
    char s[35];
    fgets(s,35,stdin);
    char num[35];
    int m=0;

    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[m]=s[i];
            m++;
        }else{
            if(m!=0){
                num[m]='\0';
                printf("%s\n",num);
                m=0;
            }
        }
    }

    return 0;
}




/*#include <stdio.h>

int main() {
    char str[31];  // 存储输入字符串（最大长度30 + 结束符'\0'）
    char current_num[31];  // 存储当前收集的连续数字
    int index = 0;  // 记录当前数字的长度（索引）

    // 读取输入字符串（支持含空格的字符串）
    fgets(str, 31, stdin);

    // 遍历字符串中的每个字符
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') {  // 若为数字，加入当前数字序列
            current_num[index++] = c;
        } else {  // 若为非数字，检查是否有已收集的数字
            if (index > 0) {  // 存在已收集的数字
                current_num[index] = '\0';  // 补充字符串结束符
                printf("%s\n", current_num);  // 输出数字
                index = 0;  // 重置索引，准备收集下一个数字
            }
        }
    }

    // 处理字符串末尾可能残留的数字（如输入以数字结束）
    if (index > 0) {
        current_num[index] = '\0';
        printf("%s\n", current_num);
    }

    return 0;
}*/