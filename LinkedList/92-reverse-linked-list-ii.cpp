// LeetCode 92 反转链表 II

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

// 个人认为，这题和25题，k个一组进行翻转有些类似
// 用 pre 记录要翻转部分的头部，即 pre->next = 翻转部分的 head
// 用 nex 记录要翻转部分的尾部的下一个元素，即不进行调换的部分的元素，调换完成部分的 tail->next = nex;
class Solution {
public:
	pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
		ListNode* prev = nullptr;
		ListNode* p = head;

		while(prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
		}
		return {tail, head};
	}

	ListNode* reverseBetween(ListNode* head, int left, int right) {

		ListNode* hair = new ListNode(0);
		hair->next = head;
		ListNode* pre = hair;
		ListNode* nex;

		int l = 1, r;

		// 遍历节点
		while(head != nullptr) {

			// 如果 l 指向的节点还没到 left 的位置
			if(l == left){

				ListNode* tail = head;

				r = l;
				while(r != right) {
					tail = tail->next;
					r++;
				}
				nex = tail->next;

				pair<ListNode*, ListNode*> result = reverse(head, tail);

				head = result.first;
				tail = result.second;

				pre->next = head;
				tail->next = nex;
				break;
			}

			l++;
			head = head->next;
			pre = pre->next;
		}

		return hair->next;
	}
};

// 官方 方法二 穿针引线
// class Solution {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right) {
//         // 设置 dummyNode 是这一类问题的一般做法
//         ListNode *dummyNode = new ListNode(-1);
//         dummyNode->next = head;
//         ListNode *pre = dummyNode;
//         for (int i = 0; i < left - 1; i++) {
//             pre = pre->next;
//         }
//         ListNode *cur = pre->next;
//         ListNode *next;
//         for (int i = 0; i < right - left; i++) {
//             next = cur->next;
//             cur->next = next->next;
//             next->next = pre->next;
//             pre->next = next;
//         }
//         return dummyNode->next;
//     }
// };