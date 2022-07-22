// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 示例 2：

// 输入：nums = []
// 输出：[]
// 示例 3：

// 输入：nums = [0]
// 输出：[]
 

// 提示：

// 0 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int n = nums.size();
    	if(n < 3) return {};

    	vector<vector<int>> res;

    	sort(nums.begin(), nums.end());

    	for(int i = 0; i < n; ++i) {
    		// 排序后，如果当前元素已经大于 0 了，说明后面的元素全部大于 0
    		// 此处相当于剪枝
    		if(nums[i] > 0) return res;

    		// 如果当前和前一个元素相同，则已经找过了，跳过
    		if(i > 0 && nums[i] == nums[i - 1]) continue;

    		int target = -nums[i];

    		int l = i + 1, r = n - 1;

    		while(l < r) {
    			if(nums[l] + nums[r] == target) {
    				res.push_back({nums[i], nums[l], nums[r]});
    				l++;
    				r--;

    				while(l < r && nums[l] == nums[l - 1]) l++;
    				while(l < r && nums[r] == nums[r + 1]) r--;
    			}
    			else if(nums[l] + nums[r] < target) l++;
    			else r--;
    		}
    	}

    	return res;
    }
};