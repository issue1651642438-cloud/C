#include <stdio.h>
#include <stdlib.h>

// 定义堆节点：存储和，以及在 A 数组中的下标
typedef struct {
    int sum;
    int idx_a;
} Node;
// 小根堆
Node heap[2005];
int heap_size;

void push(int sum, int idx_a) {
    int i = ++heap_size;
    while (i > 1) {
        int p = i / 2;
        if (heap[p].sum <= sum) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i].sum = sum;
    heap[i].idx_a = idx_a;
}

Node pop() {
    Node res = heap[1];
    Node x = heap[heap_size--];
    int i = 1;
    while (i * 2 <= heap_size) {
        int child = i * 2;
        if (child < heap_size && heap[child + 1].sum < heap[child].sum) child++;
        if (x.sum <= heap[child].sum) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = x;
    return res;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int A[2005], B[2005], temp_res[2005];

void solve() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return;

    // 读入第一行并排序，作为初始的“当前最小和”
    for (int j = 0; j < n; j++) scanf("%d", &A[j]);
    qsort(A, n, sizeof(int), cmp);

    // 循环处理剩下的 m-1 行
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &B[j]);
        qsort(B, n, sizeof(int), cmp); // 保证 B 也有序

        // 开始合并 A 和 B
        heap_size = 0;
        // 初始化堆：把 A[0] + B[j] 全入堆
        for (int j = 0; j < n; j++) {
            push(A[0] + B[j], 0);
        }

        // 依次提取 n 个最小和
        for (int k = 0; k < n; k++) {
            Node top = pop();
            temp_res[k] = top.sum;
            
            // 如果 A 还没用完，就把同一列的 (A[下一个] + B[j]) 补进去
            if (top.idx_a + 1 < n) {
                // 原理：top.sum - A[top.idx_a] 还原出 B[j]
                int current_b = top.sum - A[top.idx_a];
                push(A[top.idx_a + 1] + current_b, top.idx_a + 1);
            }
        }
        // 把结果更新回 A，准备下一次合并
        for (int k = 0; k < n; k++) A[k] = temp_res[k];
    }

    // 最终输出 A
    for (int i = 0; i < n; i++) {
        printf("%d%c", A[i], (i == n - 1 ? '\n' : ' '));
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        solve();
    }
    return 0;
}