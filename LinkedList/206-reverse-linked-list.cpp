/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 206. 反转链表
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

// 示例 1：


// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]
// 示例 2：


// 输入：head = [1,2]
// 输出：[2,1]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目范围是 [0, 5000]
// -5000 <= Node.val <= 5000
 

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
        // 递归解法
        if (head == nullptr || head->next == nullptr) {
        	return head;
        }

        // 1 2 3 4 5，cur 当前指的是 5
        ListNode* cur = reverseList(head->next);
        // 4->next->next 即 5->next 指向 4
        head->next->next = head;
        // 断开
        head->next = nullptr;
        // 返回头节点 5，返回上层，head变为 3
        return cur;
    }
    // ListNode* reverseList(ListNode* head) {
    //     // 常规解法，头插法
    //     ListNode* p = head;
    //     ListNode* q = nullptr;

    //     ListNode* tmp;
    //     while(p != nullptr) {
    //         tmp = p->next;

    //         p->next = q;
    //         q = p;
    //         p = tmp;
    //     }

    //     return q;
    // }
};