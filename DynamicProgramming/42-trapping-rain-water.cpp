// 42. 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

// 示例 1：



// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 示例 2：

// 输入：height = [4,2,0,3,2,5]
// 输出：9
 

// 提示：

// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5

// 单调栈解法

class Solution {
public:
    int trap(vector<int>& height) {
    	stack<int> st;

    	int ans = 0;

    	for(int i = 0; i < height.size(); ++i) {
    		while(!st.empty() && height[i] > height[st.top()]) {
    			// 栈顶 4 1 1 3， cur = 右 1
    			int cur = st.top();
    			st.pop();		// 弹出右 1

    			if(st.empty()) break;	// 空了

    			int left = st.top();	// 找到当前位置的左边界
    			int right = i;	// 右边界

    			// h = min(3, 1) - 1 = 0, 此时未接到水
    			int h = min(height[right], height[left]) - height[cur];
    			ans += (right - left - 1) * h;
    		}
    		st.push(i);
    	}

    	return ans;
    }
};