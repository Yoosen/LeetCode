#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
    	this->val = x;
    	this->left = null;
    	this->right = null;
    }
};

int main()
{
	int n, v1, v2;
	scanf("%d%d%d", &n, &v1, &v2);

	// int rootVal, rootLeft;
	// scanf("%d", &rootVal, &rootLeft);

	// TreeNode root = new TreeNode(rootVal);
	TreeNode aNode, bNode;

	int a, b, temp = -1;
	for(int i = 0; i < n - 1; i++) {
		scanf("%d%d",&a, &b);
		if (temp != a) {
			aNode = new TreeNode(a);
		}
		int temp = b;
		bNode = new TreeNode(b);
		if(aNode->left == null) aNode->left = bNode;
		else root->right = bNode;
	}

	return 0;
}