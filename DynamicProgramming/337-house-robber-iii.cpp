// 337. 打家劫舍 III
// 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

 

// 示例 1:



// 输入: root = [3,2,3,null,3,null,1]
// 输出: 7 
// 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
// 示例 2:



// 输入: root = [3,4,5,1,3,null,1]
// 输出: 9
// 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 

// 提示：

// 树的节点数在 [1, 10^4] 范围内
// 0 <= Node.val <= 10^4

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
    int rob(TreeNode* root) {
    	pair<int, int> res = helper(root);

    	return max(res.first, res.second);
    }

    pair<int, int> helper(TreeNode* root) {
    	if(root == nullptr) return make_pair(0, 0);

    	pair<int, int> res;

    	pair<int, int> left = helper(root->left);
    	pair<int, int> right = helper(root->right);

    	// 当前不偷，孩子偷到的最多的钱
    	res.first = max(left.first, left.second) + max(right.first, right.second);
    	// 当前节点偷，孩子不能偷 加上当前节点可偷的钱
    	res.second = left.first + right.first + root->val;

    	return res;
    }
};