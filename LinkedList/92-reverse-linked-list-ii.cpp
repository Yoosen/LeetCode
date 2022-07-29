// 92. 反转链表 II
// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

// 示例 1：


// 输入：head = [1,2,3,4,5], left = 2, right = 4
// 输出：[1,4,3,2,5]
// 示例 2：

// 输入：head = [5], left = 1, right = 1
// 输出：[5]
 

// 提示：

// 链表中节点数目为 n
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 

// 进阶： 你可以使用一趟扫描完成反转吗？

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    	if(left == right || head == nullptr || head->next == nullptr)
    		return head;

    	ListNode* dummy = new ListNode(-1);		// 头节点可能也会改变，因此添加哑节点
    	ListNode* nxt = nullptr;
    	dummy->next = head;

    	ListNode* pre = dummy;
    	ListNode* first, *second = head;

    	for(int i = 1; i < right; ++i) {
    		if(i < left) {
    			pre = pre->next;	// 走到 first 前一个节点，区间链表的头节点的上一个节点
    		}
    		second = second->next;	// 走到 second 节点
    	}

    	nxt = second->next;		// 区间链表的尾节点的下一个节点
    	pair<ListNode*, ListNode*> result = reverse(pre->next, second);

    	pre->next = result.first;		// 反转之后，重新连接
    	result.second->next = nxt;

    	return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* first, ListNode* second) {
    	ListNode*prev = nullptr, *q = first;

    	while(prev != second) {
    		ListNode* nxt = q->next;
    		q->next = prev;
    		prev = q;
    		q = nxt;
    	}

    	return {second, first};
    }
};