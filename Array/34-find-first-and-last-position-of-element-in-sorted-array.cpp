// LeetCode 34 在排序数组中查找元素的第一个和最后一个位置

// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 进阶：

// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

// 示例 1：

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：

// 输入：nums = [], target = 0
// 输出：[-1,-1]
 

// 提示：

// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// nums 是一个非递减数组
// -10^9 <= target <= 10^9

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	// 以下备注能通过
    	// if(nums.empty()) return {-1, -1};

    	// int left = 0, right = nums.size() - 1;
    	// pair<int, int> res(-1, -1);

    	// for(int i = 0; i < nums.size(); i++) {
    	// 	if(nums[i] == target && res.first == -1) {
    	// 		res.first = i;
    	// 		res.second = i;
    	// 	}

    	// 	if(nums[i] == target && res.second < i)
    	// 		res.second = i;
    	// }

    	// return {res.first, res.second};

    	if(nums.empty()) return {-1, -1};

    	int left = 0, right = nums.size() - 1;	// 左闭右开

    	// 寻找左侧边界
    	while(left <= right) {
    		int mid = left + (right - left) / 2;
    		if(nums[mid] >= target) {
    			right = mid - 1;	// 大于等于 target 收缩右侧
    		}
    		else
    			left = mid + 1;	
    	}

    	// 有可能出界
    	if(left >= nums.size() || nums[left] != target) return {-1, -1};

    	int L = left;
    	left = 0, right = nums.size() - 1;	// 重置 left， right

		// 寻找右侧边界
    	while(left <= right) {
    		int mid = left + (right - left) / 2;
    		// 这个一定能成立
    		// if(nums[mid] > target) {
    		// 	right = mid;
    		// }
    		if(nums[mid] <= target)
    			left = mid + 1;
    		else 
    			right = mid - 1;
    	}
    	return {L, right};
    }
};