// LeetCode 85 最大矩形

// 85. 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

// 示例 1：


// 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// 输出：6
// 解释：最大矩形如上图所示。
// 示例 2：

// 输入：matrix = []
// 输出：0
// 示例 3：

// 输入：matrix = [["0"]]
// 输出：0
// 示例 4：

// 输入：matrix = [["1"]]
// 输出：1
// 示例 5：

// 输入：matrix = [["0","0"]]
// 输出：0
 

// 提示：

// rows == matrix.length
// cols == matrix[0].length
// 1 <= row, cols <= 200
// matrix[i][j] 为 '0' 或 '1'

// 无法通过测试用例 [["1","0"],["1","0"]]，未发现错误所在处

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;

        // 初始化单层柱状图 
        vector<int> heights(n, 0); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 更新单层柱状图
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            // 送入单调栈方法获得结果
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }

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