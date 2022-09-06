// 9.5 阿里面试 手撕代码

#include <iostream>

using namespace std;

// 循环链表结点
class Node {
public:
    Node *next;
    int val;

    Node(Node *next, int val) : next(next), val(val) {}
};

// 问题是：1 ~ n 个人报数，数到 3 退出，最后一个退出的人是谁？
// 循环报数问题，当时说法是采用数组，实际上更好的方式是采用循环链表

// 该问题 2 步完成
// 1. 创建循环链表
// 2. 循环删除数到 3 的元素

int main() {
    int n;
    cin >> n;

    // first. 创建循环链表
    // 创建头节点，初值为 1
    Node *node = new Node(nullptr, 1);

    Node *p = node;

    // 构造整个循环链表
    for (int i = 1; i < n; ++i) {
        Node *curNode = new Node(nullptr, i + 1);

        p->next = curNode;
        p = curNode;
    }

    // second. 删除数到 3 的元素
    // 最后一个结点 next 指向头节点
    p->next = node;

    // 被删结点的前一个结点
    Node *pre = node->next;
    // 被删结点
    p = node->next->next;

    // third. 循环删除数到 3 的元素
    // 当被删结点的前一个结点和被删结点指向的是同一个元素，说明出现的是循环，也就是肯定只剩下一个元素
    // 即循环结束条件
    while (pre != p) {
        Node *tmp = p->next;
        pre->next = tmp;

        pre = tmp->next;
        p = tmp->next->next;
    }

    // 输出值
    cout << pre->val << endl;
    // 测试两者指向的是同一个节点
    cout << p->val << endl;
}