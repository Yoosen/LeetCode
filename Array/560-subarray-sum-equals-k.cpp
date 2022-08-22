// 560. 和为 K 的子数组
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

 

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2
 

// 提示：

// 1 <= nums.length <= 2 * 10^4
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int, int> mp;

    	int count = 0;

    	int preSum = 0;
    	for(auto& num : nums) {
    		preSum += num;

    		if(mp.count(preSum - k)) {
    			count += mp[preSum - k];
    		}

    		mp[preSum]++;
    	}

    	return count;
    }
};