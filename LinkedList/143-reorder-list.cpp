// 143. 重排链表
// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

// L0 → L1 → … → Ln - 1 → Ln
// 请将其重新排列后变为：

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

// 示例 1：



// 输入：head = [1,2,3,4]
// 输出：[1,4,2,3]
// 示例 2：



// 输入：head = [1,2,3,4,5]
// 输出：[1,5,2,4,3]
 

// 提示：

// 链表的长度范围为 [1, 5 * 104]
// 1 <= node.val <= 1000

// 存储节点占用空间 O(n)，时间复杂度 O(n)

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
    void reorderList(ListNode* head) {
    	if(head == nullptr)
    		return ;

    	vector<ListNode*> v;

    	while(head != nullptr) {
    		v.push_back(head);
    		head = head->next;
    	}

    	int l = 0, r = v.size() - 1;
    	while(l < r) {
    		v[l]->next = v[r];
    		l++;

    		if(l == r)
    			break;

    		v[r]->next = v[l];
    		r--;
    	}
    	v[l]->next = nullptr;
    }
};