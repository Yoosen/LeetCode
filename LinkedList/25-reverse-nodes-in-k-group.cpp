// 25. K 个一组翻转链表
// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

// 示例 1：


// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]
// 示例 2：



// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]
 

// 提示：
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while(head) {
            ListNode* tail = pre;

            for(int i = 0; i < k; ++i) {
                tail = tail->next;

                // 如果已经到尾部了，不用继续调整。直接返回结果
                if(!tail) {
                    return hair->next;
                }
            }

            // 保留 k 个一组的后一个节点
            ListNode* nxt = tail->next;
            pair<ListNode*, ListNode*> result = reverse(head, tail);

            // 反转之后的头尾
            head = result.first;
            tail = result.second;
            // 将反转之后的链表接上去
            pre->next = head;
            tail->next = nxt;

            // 继续下一组
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* p = head;

        while(prev != tail) {
            ListNode* nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }

        return {tail, head};
    }
};