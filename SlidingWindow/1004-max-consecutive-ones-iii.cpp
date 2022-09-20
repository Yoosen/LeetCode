// 1004. 最大连续1的个数 III
// 给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

 

// 示例 1：

// 输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
// 输出：6
// 解释：[1,1,1,0,0,1,1,1,1,1,1]
// 粗体数字从 0 翻转到 1，最长的子数组长度为 6。
// 示例 2：

// 输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
// 输出：10
// 解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// 粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

// 提示：

// 1 <= nums.length <= 10^5
// nums[i] 不是 0 就是 1
// 0 <= k <= nums.length

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    	int res = 0, zeros = 0, l = 0, r = 0;
    	int n = nums.size();

    	while(r < n) {
    		if(nums[r] == 0) ++zeros;

    		while(zeros > k) {
    			if(nums[l++] == 0) --zeros;
    		}
    		res = max(res, r - l + 1);

    		++r;
    	}
    	return res;
    }
};