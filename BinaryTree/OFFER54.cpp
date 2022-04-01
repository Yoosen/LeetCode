// 剑指 Offer 54. 二叉搜索树的第k大节点
// 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。

 

// 示例 1:

// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
// 示例 2:

// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4
 

// 限制：

// 1 ≤ k ≤ 二叉搜索树元素个数

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
	int res;
    int kthLargest(TreeNode* root, int k) {
    	traverse(root, k);
    	return res;
    }

    void traverse(TreeNode* root, int& k) {
    	if(root == NULL) return ;

    	traverse(root->right, k);

    	if(--k == 0) res = root->val;

    	traverse(root->left, k);
    }
};