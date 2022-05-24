// LeetCode 83 删除排序链表中的重复元素

// 83. 删除排序链表中的重复元素
// 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

 

// 示例 1：


// 输入：head = [1,1,2]
// 输出：[1,2]
// 示例 2：


// 输入：head = [1,1,2,3,3]
// 输出：[1,2,3]
 

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
    	ListNode* cur = head;

    	// 第一个 cur 是判断特例的，节点为 0 或 1
    	while(cur != nullptr && cur->next != nullptr) {
    		if(cur->val == cur->next->val)
    			cur->next = cur->next->next;
    		else 
    			cur = cur->next;
    	}
    	return head;
    }
};