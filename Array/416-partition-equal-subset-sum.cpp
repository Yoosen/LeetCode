// 416. 分割等和子集
// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

// 示例 1：

// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// 示例 2：

// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。
 

// 提示：

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

// dp[i][j] 表示选取在数据 [0, i] 区间内选取一些正整数，使之和恰好等于 j

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	int n = nums.size();

    	// 奇数
    	if((sum & 1) == 1) {
    		return false;
    	}

    	int target = sum >> 1;

    	vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));

    	// 都不选
    	for(int i = 0; i <= n; ++i) {
    		dp[i][0] = true;
    	}

    	for(int i = 1; i <= n; ++i) {
    		for(int j = 0; j <= target; ++j) {
    			// 当前数不能选，大于目标值 j
    			if(nums[i - 1] > j) {
    				dp[i][j] = dp[i - 1][j];
    			} else {
    				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    			}
    		}
    	}
    	return dp[n][target];
    }
};