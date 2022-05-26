// LeetCode 128 最长连续序列

// 128. 最长连续序列
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1：

// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：

// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
 

// 提示：

// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_set<int> set;

    	for(auto num : nums) {
    		set.insert(num);
    	}

    	int ans = 0;

    	for(auto num : nums) {
    		int cur = num;
    		if(!set.count(num - 1)) {
    			// contains() C++ 20 的方法
    			while(set.count(cur + 1)) {
    				cur++;
    			}
    			ans = max(ans, cur - num + 1);
    		}
    	}
    	return ans;
    }
};