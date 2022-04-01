// 剑指 Offer 55 - I. & LeetCode 104 二叉树的深度

// 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

// 例如：

// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int depth = 0;
	int res = 0;
    int maxDepth(TreeNode* root) {

    	traverse(root);

    	return res;
    }

    void traverse(TreeNode* root) {
    	if(root == NULL) {
    		res = max(res, depth);
    		return ;
    	}

    	depth++;
    	traverse(root->left);
    	traverse(root->right);
    	depth--;
    }
};