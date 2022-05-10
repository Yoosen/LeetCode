// LeetCode 101 对称二叉树

// 101. 对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

 

// 示例 1：


// 输入：root = [1,2,2,3,4,4,3]
// 输出：true
// 示例 2：


// 输入：root = [1,2,2,null,3,null,3]
// 输出：false
 

// 提示：

// 树中节点数目在范围 [1, 1000] 内
// -100 <= Node.val <= 100
 

// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	return isMirror(root, root);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
    	if(left == nullptr && right == nullptr)
    		return true;

    	if(left == nullptr || right == nullptr)
    		return false;

    	if(left->val != right->val)
    		return false;

    	return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};