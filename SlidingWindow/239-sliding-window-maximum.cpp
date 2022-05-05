// LeetCode 239 滑动窗口最大值

// 239. 滑动窗口最大值
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

 

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：

// 输入：nums = [1], k = 1
// 输出：[1]
 

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> ans;
    	
    	if(nums.size() < 2) return nums;

		// 双向队列 保存当前窗口最大值的数组位置 保证队列中数组位置的数值按从大到小排序
    	deque<int> dq;

    	// 遍历数组
    	for(int i = 0; i < nums.size(); i++) {

    		// 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
    		while(!dq.empty() && nums[dq.back()] <= nums[i]) {
    			dq.pop_back();
    		}

    		// 添加当前值对应的数组下标
    		dq.push_back(i);

			// 判断当前队列中队首的值是否有效，是否在区间范围
    		if(dq.front() <= i - k) {
    			dq.pop_front();
    		}

			// 当窗口长度为 k 时 保存当前窗口中最大值
    		if(i + 1 >= k) {
    			ans.push_back(nums[dq.front()]);
    		}
    	}
    	return ans;
    }
};