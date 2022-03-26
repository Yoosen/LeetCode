#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void backtrack(TreeNode* cur, vector<int>& path, vector<string>& res) {
	path.push_back(cur->val);
	if (cur->left == nullptr && cur->right == nullptr)
	{
		string sPath;
		for (int i = 0; i < path.size() - 1; ++i)
		{
			sPath += to_string(path[i]);
			sPath += "->";
		}
		sPath += to_string([path.size() - 1]);
		res.push_back(sPath);
		return;
	}

	if (cur->left != nullptr) {
		backtrack(cur->left, path, res);
	}

	if (cur->right != nullptr) {
		backtrack(cur->right, path, res);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	vector<int> path;
	if (root == NULL) return res;
	backtrack(root, path, res);
	return res;
}

int main(){
	

	return 0;
}