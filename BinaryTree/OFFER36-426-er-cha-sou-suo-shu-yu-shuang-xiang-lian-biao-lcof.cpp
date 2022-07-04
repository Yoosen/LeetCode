// 剑指 Offer 36. 二叉搜索树与双向链表
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 

// 为了让您更好地理解问题，以下面的二叉搜索树为例：

 



 

// 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

// 下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

 



 

// 特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

 

// 注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

// 注意：此题对比原题有改动。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        traverse(root);
        // 注意，上面的方法中，我们只是把第一个接点到
        // 最后一个节点串了起来，但并没有把第一个节点
        // 和最后一个节点串起来连成一个环形，所以这里
        // 还要把链表的首尾连接起来（这里pre已经是尾节点了）
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    // head 记录头结点，用来最后返回的
    // pre记录遍历的当前节点的前一个节点, 用来把当前节点给串起来的
    Node *pre, *head;

    void traverse(Node* cur) {
        if (cur == NULL) return ;

        traverse(cur->left);

        if(pre == NULL) {
            // 这行代码只会执行一次，就是root是树的左子节点的左子节点的……,
            // 一直没有左子节点为止,实际上就是中序遍历结果的第一个节点
            head = cur;
        }
        else {
            // 串起来的结果就是前一个节点pre的right指向当前节点，
            // 然后当前节点的left指向前一个节点pre
            pre->right = cur;
        }
        cur->left = pre;

        // 前一个节点和当前节点串起来之后，就让当前节点变成前一个节点
        pre = cur;

        traverse(cur->right);
    }
};