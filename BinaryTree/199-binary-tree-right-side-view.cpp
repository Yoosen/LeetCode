// LeetCode 199 二叉树的右视图

// 199. 二叉树的右视图
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

// 示例 1:



// 输入: [1,2,3,null,5,null,4]
// 输出: [1,3,4]
// 示例 2:

// 输入: [1,null,3]
// 输出: [1,3]
// 示例 3:

// 输入: []
// 输出: []
 

// 提示:

// 二叉树的节点个数的范围是 [0,100]
// -100 <= Node.val <= 100

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
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> res;

    	if(root == nullptr)
    		return res;

    	queue<TreeNode*> q;

    	q.push(root);

    	while(!q.empty()) {
    		int n = q.size();


    		for(int i = 0; i < n; i++) {
    			TreeNode* node = q.front();
    			q.pop();

    			if(i == n - 1) {
    				res.push_back(node->val);
    			}

    			if(node->left != nullptr) {
    				q.push(node->left);
    			}

    			if(node->right != nullptr) {
    				q.push(node->right);
    			}
    		}
    	}

    	return res;
    }
};