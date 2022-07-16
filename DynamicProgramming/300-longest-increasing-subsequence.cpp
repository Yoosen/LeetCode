// 300. 最长递增子序列
// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
// 示例 1：

// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：

// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 示例 3：

// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1
 

// 提示：

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4
 

// 进阶：

// 你能将算法的时间复杂度降低到 O(n log(n)) 吗?


// tail[i] 表示：长度为 i + 1 的 所有 上升子序列的结尾的最小值。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	if(n < 2)
    		return n;

    	vector<int> tail;
    	tail.push_back(nums[0]);
    	// tail结尾的索引
    	int end = 0;

    	for(int i = 1; i < n; ++i) {
    		// 如果当前值大于tail的最后一个元素，加上去
    		if(nums[i] > tail[end]) {
    			tail.push_back(nums[i]);
    			end++;
    		}
    		// 如果小于等于当前tail的最后一个元素，在tail内的元素找一个比当前元素大的，替换过去
    		else {
    			int l = 0, r = end;
    			while(l < r) {
    				int m = l + (r - l) / 2;
    				if(tail[m] < nums[i]) {
    					l = m + 1;
    				} else {
    					r = m;
    				}
    			}
    			tail[l] = nums[i];
    		}
    	}

    	return end + 1;
    }
};