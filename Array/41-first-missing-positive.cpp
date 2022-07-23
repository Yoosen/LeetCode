// 41. 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

// 示例 1：

// 输入：nums = [1,2,0]
// 输出：3
// 示例 2：

// 输入：nums = [3,4,-1,1]
// 输出：2
// 示例 3：

// 输入：nums = [7,8,9,11,12]
// 输出：1
 

// 提示：

// 1 <= nums.length <= 5 * 10^5
// -2^31 <= nums[i] <= 2^31 - 1

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	for(int i = 0; i < nums.size(); ++i) {
    		// e.g. nums[0] != 1
    		while(nums[i] != i + 1) {
    			// 注意最后一个条件
    			// 表示当前需要交换的两个值是否相同,相同的话就不需要重复交换导致死循环,
    			//因为你遍历到第二个重复的值时,总会和第一个已经放在正确位置的值交换,这两个值就会一直交换
    			if(nums[i] < 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
    				break;

    			int idx = nums[i] - 1;
    			swap(nums[i], nums[idx]);
    		}
    	}

    	for(int i = 0; i < nums.size(); ++i) {
    		if(nums[i] != i + 1)
    			return (i + 1);
    	}

    	return nums.size() + 1;
    }
};