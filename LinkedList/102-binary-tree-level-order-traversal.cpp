// 102. 二叉树的层序遍历
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数目在范围 [0, 2000] 内
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> r;

        if(root == nullptr) return res;

        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()) {
            int sz = que.size();

            for(int i = 0; i < sz; ++i) {
                TreeNode* node = que.front();

                que.pop();

                r.push_back(node->val);

                if(node->left != nullptr) {
                    que.push(node->left);
                }

                if(node->right != nullptr) {
                    que.push(node->right);
                }
            }

            res.push_back(r);
            r.clear();
        }

        return res;
    }
};