// 312. 戳气球
// 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

// 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

// 求所能获得硬币的最大数量。

 

// 示例 1：
// 输入：nums = [3,1,5,8]
// 输出：167
// 解释：
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// 示例 2：

// 输入：nums = [1,5]
// 输出：10
 

// 提示：

// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	int n = nums.size();

    	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    	vector<int> temp(n + 2);
    	// 填充首尾
    	temp[0] = 1;
    	temp[n + 1] = 1;
    	for(int i = 1; i < n + 1; ++i)
    		temp[i] = nums[i - 1];

    	// 遍历每一个区间长度，最小为 3
    	for(int len = 3; len <= n + 2; ++len) {
    		// l表示开区间左端点, l + len - 1则表示开区间右端点
    		for(int l = 0; l <= n + 2 - len; ++l) {
    			//k为开区间内的索引（代表区间最后一个被戳破的气球）
    			for(int k = l + 1; k < l + len - 1; k++) {
    				int left = dp[l][k];
    				int right = dp[k][l + len - 1];

    				int sum = left + right + temp[k] * temp[l] * temp[l + len - 1];
    				dp[l][l + len - 1] = max(dp[l][l + len - 1], sum);
    			}
    		}
    	}

    	return dp[0][n + 1];
    }
};