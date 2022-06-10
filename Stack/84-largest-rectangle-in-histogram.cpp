// LeetCode 84 柱状图中最大的矩形

// 84. 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

// 示例 1:



// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10
// 示例 2：



// 输入： heights = [2,4]
// 输出： 4
 

// 提示：

// 1 <= heights.length <=10^5
// 0 <= heights[i] <= 10^4


// 单调栈
// 单调栈分为单调递增栈和单调递减栈
// 11. 单调递增栈即栈内元素保持单调递增的栈
// 12. 同理单调递减栈即栈内元素保持单调递减的栈

// 操作规则（下面都以单调递增栈为例）
// 21. 如果新的元素比栈顶元素大，就入栈
// 22. 如果新的元素较小，那就一直把栈内元素弹出来，直到栈顶比新元素小

// 加入这样一个规则之后，会有什么效果
// 31. 栈内的元素是递增的
// 32. 当元素出栈时，说明这个新元素是出栈元素向后找第一个比其小的元素

// 举个例子，现在索引在 6 ，栈里是 1 5 6 。
// 接下来新元素是 2 ，那么 6 需要出栈。
// 当 6 出栈时，右边 2 代表是 6 右边第一个比 6 小的元素。

// 当元素出栈后，说明新栈顶元素是出栈元素向前找第一个比其小的元素
// 当 6 出栈时，5 成为新的栈顶，那么 5 就是 6 左边第一个比 6 小的元素。

// 代码模板

// C++

// stack<int> st;
// for(int i = 0; i < nums.size(); i++)
// {
// 	while(!st.empty() && st.top() > nums[i])
// 	{
// 		st.pop();
// 	}
// 	st.push(nums[i]);
// }

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		// 原始数组前后加入一个 0 
		heights.insert(heights.begin(), 0);
		heights.push_back(0);

		stack<int> st;	// 单调递增栈

		int res = 0;

		for(int i = 0; i < heights.size(); i++) {
			while(!st.empty() && heights[i] < heights[st.top()]) {
				// 数组中找到出栈元素的高度
				int curHeight = heights[st.top()];
				// 弹出这个元素
				st.pop();
				//找到其左边界，即弹出元素的左侧一个元素，也就是新的栈顶
				int leftIndex = st.top();
				// 找到其右边界，也就是 i，当前遍历的那个
				int rightIndex = i;

				res = max(res, (rightIndex - leftIndex - 1) * curHeight);

			}
			st.push(i);
		}

		return res;
	}
};