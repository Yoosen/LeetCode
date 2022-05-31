// LeetCode 24 两两交换链表中的节点

// 24. 两两交换链表中的节点
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

// 示例 1：


// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]
 

// 提示：

// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) return head;

    	ListNode* dummy = new ListNode(-1);
    	dummy->next = head;
    	ListNode* tmp = dummy;

    	while(tmp->next != nullptr && tmp->next->next != nullptr) {
    		ListNode* node1 = tmp->next;
    		ListNode* node2 = tmp->next->next;

    		tmp->next = node2;
    		node1->next = node2->next;
    		node2->next = node1;
    		tmp = node1;
    	}
    	return dummy->next;
    }
};