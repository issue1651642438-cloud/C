#include <iostream>
struct Node {
    int val;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;        // 初始化前驱节点
    Node* curr = head;           // 初始化当前节点
    while (curr != nullptr) {
        Node* nextTemp = curr->next;   // 保存下一个节点
        curr->next = prev;             // 反转指针
        prev = curr;                   // 前驱节点向前移动
        curr = nextTemp;               // 当前节点向前移动
    }
    return prev;                        // 返回新头节点
}

int main() {
    // 创建简单链表 1->2->3->nullptr
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    head = reverseList(head);

    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}

#include <iostream>
struct Node {
    int val;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = __________;     // 初始化前驱节点
    Node* curr = __________;     // 初始化当前节点
    while (curr != nullptr) {
        Node* nextTemp = __________;   // 保存下一个节点
        curr->next = __________;       // 反转指针
        prev = __________;             // 前驱节点向前移动
        curr = __________;             // 当前节点向前移动
    }
    return __________;                 // 返回新头节点
}

int main() {
    // 创建简单链表 1->2->3->nullptr
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    head = reverseList(head);

    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}