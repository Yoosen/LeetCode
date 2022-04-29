// LeetCode 144 二叉树的前序遍历

// 144. 二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

 

// 示例 1：


// 输入：root = [1,null,2,3]
// 输出：[1,2,3]
// 示例 2：

// 输入：root = []
// 输出：[]
// 示例 3：

// 输入：root = [1]
// 输出：[1]
// 示例 4：


// 输入：root = [1,2]
// 输出：[1,2]
// 示例 5：


// 输入：root = [1,null,2]
// 输出：[1,2]
 

// 提示：

// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
 

// 进阶：递归算法很简单，你可以通过迭代算法完成吗？

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
    vector<int> preorderTraversal(TreeNode* root) {
    	if(root == nullptr) return {};

    	vector<int> v;
    	stack<TreeNode*> s;
    	TreeNode* node = root;

    	while(node != nullptr || !s.empty()) {
    		while(node != nullptr) {
    			v.push_back(node->val);	// 入栈时将根和左孩子节点加入到结果中
    			s.push(node);
    			node = node->left;
    		}

    		node = s.top();
    		s.pop();
    		// 最后再找右孩子
    		node = node->right;
    	}


    	return v;
    }
};


// class Solution {
// public:
// 	void preorder(TreeNode* root, vector<int>& v) {
// 		if(!root)
// 			return ;

// 		v.push_back(root->val);
// 		preorder(root->left, v);
// 		preorder(root->right, v);
// 	}

//     vector<int> preorderTraversal(TreeNode* root) {
//     	vector<int> v;

//     	preorder(root, v);

//     	return v;
//     }
// };