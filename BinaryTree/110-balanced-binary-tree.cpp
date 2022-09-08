// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：true
// 示例 2：


// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
// 示例 3：

// 输入：root = []
// 输出：true
 

// 提示：

// 树中的节点数在范围 [0, 5000] 内
// -10^4 <= Node.val <= 10^4

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
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }

    int recur(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int left = recur(root->left);
        if(left == -1) return -1;

        int right = recur(root->right);
        if(right == -1) return -1;

        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};