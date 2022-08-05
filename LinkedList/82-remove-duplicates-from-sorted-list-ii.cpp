// 82. 删除排序链表中的重复元素 II
// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

 

// 示例 1：


// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]
// 示例 2：


// 输入：head = [1,1,1,2,3]
// 输出：[2,3]
 

// 提示：

// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序 排列

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101);

        ListNode* pre = dummy;
        pre->next = head;

        ListNode* cur = head;

        while(cur != nullptr && cur->next != nullptr) {
            if(cur->val == cur->next->val) {
            	int x = cur->val;

            	while(cur != nullptr && cur->val == x) {
            		cur = cur->next;
            	}

            	pre->next = cur;
            }
            else {
            	pre->next = cur;
            	pre = pre->next;

            	cur = cur->next;
            }
        }

        return dummy->next;
    }
};