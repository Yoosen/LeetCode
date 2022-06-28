// 581. 最短无序连续子数组
// 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

// 请你找出符合题意的 最短 子数组，并输出它的长度。

 

// 示例 1：

// 输入：nums = [2,6,4,8,10,9,15]
// 输出：5
// 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 示例 2：

// 输入：nums = [1,2,3,4]
// 输出：0
// 示例 3：

// 输入：nums = [1]
// 输出：0
 

// 提示：

// 1 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5
 

// 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？

// https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/si-lu-qing-xi-ming-liao-kan-bu-dong-bu-cun-zai-de-/
// 那么我们目标就很明确了，找中段的左右边界，我们分别定义为begin 和 end;
// 分两头开始遍历:

// 从左到右维护一个最大值max,在进入右段之前，那么遍历到的nums[i]都是小于max的，我们要求的end就是遍历中最后一个小于max元素的位置；
// 同理，从右到左维护一个最小值min，在进入左段之前，那么遍历到的nums[i]也都是大于min的，要求的begin也就是最后一个大于min元素的位置。

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	int n = nums.size();
    	int maxN = nums[0], minN = nums[n - 1];
    	int begin = 0, end = -1;

    	for(int i = 0; i < n; ++i) {
    		// 从左到右维持最大值，找右边界
    		if(nums[i] < maxN) {
    			end = i;
    		}
    		else {
    			maxN = nums[i];
    		}

    		// 从右到左维持最小值，找左边界
    		if(nums[n - i - 1] > minN) {
    			begin = n - i - 1;
    		}
    		else {
    			minN = nums[n - i - 1];
    		}
    	}

    	return end - begin +
    }
};