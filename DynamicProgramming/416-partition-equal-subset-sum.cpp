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

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);

    	if(sum & 1 == 1)	// 如果是奇数
    		return false;

    	int target = sum >> 1;
    	vector<bool> dp(target + 1, false);
    	dp[0] = true;

    	for(int i = 0; i < nums.size(); ++i) {
    		int num = nums[i];
            // 如果是正序的话，j会使用本行的值，实际上应该使用上一行的值
            // 所以应该倒序，使其使用上一行左上角和正上方的值进行更新
            // 如果当前 [0, i]区间的数在容量 j的情况下已经
            // 当 j为容量小于当前值（重量），都不需要了，继承上一轮
    		for(int j = target; j >= num; --j) {
    			if(dp[target])
    				return true;
    			dp[j] = dp[j] || dp[j - num];
    		}
    	}

    	return dp[target];
    }
};