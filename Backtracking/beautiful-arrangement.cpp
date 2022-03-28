// LeetCode 526. 优美的排列

// 假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：

// perm[i] 能够被 i 整除
// i 能够被 perm[i] 整除
// 给你一个整数 n ，返回可以构造的 优美排列 的 数量 。

class Solution {
public:

	int ans = 0;

	vector<bool> visited(n + 1, false);

	void backtrack(int n, int index) {
		if(index == n + 1) {
			ans++;
			return ;
		}

		for(int i = 1; i <= n; i++) {
			if(used[i] != true && (nums[i] % i == 0 || i % nums[i] == 0)) {
				
				used[i] = true;
				backtrack(nums, used);
				used[i] = false;
			}	
		}
	}

	int countArrangement(int n) {

		backtrack(n, 1);

		return ans;
	}
};