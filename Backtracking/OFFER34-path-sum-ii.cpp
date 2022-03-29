// LeetCode 113 & 剑指 Offer 34

// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。



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
	vector<vector<int>> res;
	vector<int> track;

	void backtrack(TreeNode* node, int target) {

		// 终止条件
		if (node == nullptr) return ;

		track.push_back(node->val);

		if (accumulate(track.begin(), track.end(), 0) == target && node->left == nullptr && node->right == nullptr) {
			res.push_back(track);
		}

		backtrack(node->left, target);
		backtrack(node->right, target);

		track.pop_back();

	}
    vector<vector<int>> pathSum(TreeNode* root, int target) {

    	backtrack(root, target);

    	return res;
    }
};