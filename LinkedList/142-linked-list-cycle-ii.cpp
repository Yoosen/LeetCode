// LeetCode 142 环形链表 II

// 142. 环形链表 II
// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

 

// 示例 1：



// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。
// 示例 2：



// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。
// 示例 3：



// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。
 

// 提示：

// 链表中节点的数目范围在范围 [0, 104] 内
// -105 <= Node.val <= 105
// pos 的值为 -1 或者链表中的一个有效索引

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        	return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // 找相遇点
        while(true) {
        	if(fast == NULL || fast->next == NULL) {
        		return NULL;
        	}
        	slow = slow->next;
        	fast = fast->next->next;

        	if(fast == slow)
        		break;
        }

        // 假设相遇点距离环起点为 m，slow 走了 k 步，那么环起点距离头节点 k - m 的距离
        // 在环内，fast一共走了 2*k 步，比 slow 多走了 k 步，巧合的是 fast从相遇点到环起点的距离也是 k - m
        // 相遇以后，让 slow 指向 head 和 fast 同步走 k - m 步，再次相遇点即是环起点
        slow = head;
        while(slow != fast) {
        	slow = slow->next;
        	fast = fast->next;
        }

        return slow;
    }
};