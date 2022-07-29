// 124. 二叉树中的最大路径和
// 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

 

// 示例 1：


// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
// 示例 2：


// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 

// 提示：

// 树中节点数目范围是 [1, 3 * 10^4]
// -1000 <= Node.val <= 1000

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

// 当前节点的贡献值取决于左右节点之一的最大贡献值
// 当前节点的最大路径和取决于当前节点值和左右两节点的最大贡献值
class Solution {
public:
	int maxSum = INT_MIN;		// 记录最大路径和

    int maxPathSum(TreeNode* root) {
    	maxGrain(root);
    	return maxSum;
    }

    // 用来计算当前节点的最大贡献值
    int maxGrain(TreeNode* node) {
    	// 递归临界条件
    	if(node == nullptr) {
    		return 0;
    	}

    	// 如果是负数，还不如不选择子节点
    	int leftGrain = max(maxGrain(node->left), 0);
    	int rightGrain = max(maxGrain(node->right), 0);

    	// 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    	maxSum = max(maxSum, leftGrain + rightGrain + node->val);

    	// 当前节点的最大贡献值是当前节点值加上左右节点的最大贡献值
    	return node->val + max(leftGrain, rightGrain);
    }
};