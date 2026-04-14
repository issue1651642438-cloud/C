#include <stdio.h>
#include <stdlib.h>

// 定义结构体，表示双向循环链表的节点
typedef struct Node {
    int val;  // 存储编号
    struct Node* prev;  // 指向前一个节点的指针
    struct Node* next;  // 指向后一个节点的指针
} Node;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // 构造双向循环链表
    Node* head = (Node*)malloc(sizeof(Node));  // 头结点
    head->val = 1;
    head->prev = NULL;
    head->next = NULL;
    
    // 尾结点，初始时和头结点一样
    // Node* tail = /*-------填空1-------*/;  
    Node* tail = head;
    
    for (int i = 2; i <= n; i++) {

        // 创建新的节点
        // Node* node = /*-------填空2-------*/;
        Node* node = (Node*)malloc(sizeof(Node));  
        node->val = i ;
        
        // tail->next = /*-------填空3-------*/;  // 把新节点接在尾部
        tail->next = node;

        node->prev = tail;

        // 新节点的后继是头结点
        // node->next = /*-------填空4-------*/;  
        node->next = head;
        
        // 头结点的前驱是新节点
        // head->prev = /*-------填空5-------*/; 
        head->prev = node; 

        // tail = /*-------填空6-------*/;  // 更新尾结点
        tail = node;  // 更新尾结点
    }

    // 模拟出圈过程
    Node* cur = head;  // 从头结点开始数数
    while (n--) {  // 循环 n 次，直到所有人都出圈
        for (int i = 1; i < k; i++) {
            cur = cur->next;  // 数到第 k 个人之前，每次移动一个节点
        }
        printf("%d ", cur->val);  // 输出当前节点的编号
        
        // 把当前节点cur从链表中删除
        
        /*-------填空7-------*/
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        /*-------填空7-------*/
        
        Node* tmp = cur->next;  // 把当前节点保存起来
        free(cur);  // 释放当前节点的内存
        cur = tmp;  // 把指针移到下一个节点，从下一个节点开始数数
    }

    return 0;
}
