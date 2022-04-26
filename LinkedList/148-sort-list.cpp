// LeetCode 148 排序链表

// 148. 排序链表
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

// 示例 1：


// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：


// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
 

// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

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
    ListNode* sortList(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) return head;

    	ListNode* slow = head;
    	ListNode* fast = head->next;

    	// 中间分割开
    	while(fast != nullptr && fast->next != nullptr) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}

    	// right 指向slow后的首届点
    	ListNode* right = slow->next;
    	slow->next = nullptr;

    	ListNode* l = sortList(head);
    	ListNode* r = sortList(right);

    	return mergeList(l, r);
    }

    // 融合两个链表
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
    	ListNode* dummy = new ListNode();
    	ListNode* tail = dummy;

    	while (l1 != nullptr && l2 != nullptr) {
	    	if(l1->val < l2->val) {
	    		tail->next = l1;
	    		tail = tail->next;
	    		l1 = l1->next;
	    	}
	    	else {
	    		tail->next = l2;
	    		tail = tail->next;
	    		l2 = l2->next;
	    	}
    	}

    	if(l1 != nullptr) tail->next = l1;
    	if(l2 != nullptr) tail->next = l2;

    	return dummy->next;
    }
};