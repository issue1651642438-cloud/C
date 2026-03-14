#include <stdio.h>

// 左开右开（双开区间）版二分查找
// 区间表示：(left, right)，既不包含left，也不包含right
// 参数：arr-升序数组，n-数组长度，target-查找目标
// 返回值：找到返回索引，未找到返回-1
int binary_search_open_both(int arr[], int n, int target) {
    // 边界处理：空数组直接返回-1
    if (n <= 0) {
        return -1;
    }

    // 左开右开区间初始化：left=-1（不包含），right=n（不包含）
    int left = -1;
    int right = n;

    // 循环条件：left + 1 < right → 区间内还有至少1个元素
    // 若left+1 >= right，区间(left, right)为空，终止循环
    while (left + 1 < right) {
        // 计算中间索引（防溢出写法，mid一定在(left, right)内，不会越界）
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // 找到目标，直接返回索引
        } else if (arr[mid] < target) {
            // 目标在右半区 (mid, right)，更新左边界为mid
            left = mid;
        } else {
            // 目标在左半区 (left, mid)，更新右边界为mid
            right = mid;
        }
    }

    // 循环结束未找到目标
    return -1;
}

// 测试函数
int main() {
    // 测试用例1：普通升序数组（有目标值）
    int arr1[] = {1, 2, 5, 5, 6, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 6;
    int index1 = binary_search_open_both(arr1, n1, target1);
    printf("数组1：");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n查找目标 %d → %s，索引：%d\n", target1, index1 != -1 ? "找到" : "未找到", index1);

    // 测试用例2：无目标值
    int target2 = 8;
    int index2 = binary_search_open_both(arr1, n1, target2);
    printf("查找目标 %d → %s，索引：%d\n", target2, index2 != -1 ? "找到" : "未找到", index2);

    // 测试用例3：单元素数组
    int arr2[] = {10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int index3 = binary_search_open_both(arr2, n2, 10);
    printf("\n数组2：%d\n查找目标 10 → %s，索引：%d\n", arr2[0], index3 != -1 ? "找到" : "未找到", index3);

    return 0;
}