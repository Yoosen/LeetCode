// 209. 长度最小的子数组
// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

// 示例 1：

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：

// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：

// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0
 

// 提示：

// 1 <= target <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^5
 

// 进阶：

// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;	// 记录窗口内的总值

        while(end < n) {
            sum += nums[end];
            // 什么时候开始收缩
            while(sum >= target) {
                ans = min(ans, end - start + 1);	// 记录信息
                sum -= nums[start];	// 更新窗口
                start++;	// 收缩
            }
            end++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};