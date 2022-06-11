// 96. 不同的二叉搜索树
// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

 

// 示例 1：


// 输入：n = 3
// 输出：5
// 示例 2：

// 输入：n = 1
// 输出：1
 

// 提示：

// 1 <= n <= 19

class Solution {
public:
	map<int, int> m;

	// 递归
    int numTrees(int n) {
    	// 0个节点和 1个节点返回的都是 1
    	if(n ==0 || n == 1) {
    		return 1;
    	}

    	if(m[n] != 0) {
    		return m[n];
    	}

    	int count = 0;
    	for(int i = 1; i <= n; i++) {
    		//当用i这个节点当做根节点时

    		// 左边树的种数
    		int leftNums = numTrees(i - 1);
    		// 右边树的种树
    		int rightNums = numTrees(n - i);

    		// 相乘，再加起来
    		count += leftNums * rightNums;
    	}

    	map[n] = count;

    	return count;
    }
};