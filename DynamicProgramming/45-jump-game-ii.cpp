// 45. 跳跃游戏 II
// 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

// 假设你总是可以到达数组的最后一个位置。

 

// 示例 1:

// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 示例 2:

// 输入: nums = [2,3,0,1,4]
// 输出: 2
 

// 提示:

// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 1000

class Solution {
public:
    int jump(vector<int>& nums) {
    	int res = 0;
    	int start = 0;	// 起跳开始的台阶
    	int end = 1;	// 起跳结束的台阶

    	// 跳到的最远位置不能到达末尾
    	while(end < nums.size()) {
    		int maxPos = 0;

    		// 在起跳范围内，找出能跳到的最远位置
    		for(int i = start; i < end; ++i) {
    			maxPos = max(maxPos, i + nums[i]);
    		}
    		start = end;		// 下次起跳范围开始位置
    		end = maxPos + 1;	// 下次起跳范围结束位置
    		res++;
    	}
    	return res;
    }
};