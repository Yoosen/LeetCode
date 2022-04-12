// LeetCode 103 二叉树的锯齿形层序遍历
// 103. 二叉树的锯齿形层序遍历
// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[20,9],[15,7]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数目在范围 [0, 2000] 内
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

// 算法思想

// 按照正常的树层次排序进行读取并存到队列，然后遍历队列，用双端队列存储每层的遍历值，flag作为标记，双端队列的最前或者最后添加元素

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (root == nullptr) return res;

		queue<TreeNode*> q;
		q.push(root);
		bool flag = true;


		while(!q.empty()) {
			int sz = q.size();

			deque<int> r;

			for(int i = 0; i < sz; i++) {
				TreeNode* node = q.front();
				q.pop();

				if (flag) {
					r.push_back(node->val);
				} else {
					r.push_front(node->val);
				}

				
				if (node->left != nullptr){
					q.push(node->left);
				}

				if (node->right != nullptr){
					q.push(node->right);
				}
			}

			res.emplace_back(vector<int>{r.begin(), r.end()});
			flag = !flag;
		}

		return res;
	}
};