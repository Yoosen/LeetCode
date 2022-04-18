// LeetCode 54 螺旋矩阵

// 54. 螺旋矩阵
// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

// 示例 1：


// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：


// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
    	if(matrix.empty()) return ans; 	// 若数组为空，则直接返回答案

    	// 上下左右边界
    	int top = 0;
    	int bottom = matrix.size() - 1;
    	int left = 0;
    	int right = matrix[0].size() - 1;

    	while(true) {
    		// 从左移动到右
    		for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
    		++top;
    		if(top > bottom) break;
    		// 从上移动到下
    		for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
    		--right;
    		if(right < left) break;
    		// 从右移动到左
    		for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
    		--bottom;
    		if(top > bottom) break;
    		// 从下移动到上
    		for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
    		++left;
    		if(right < left) break;
    	}

    	return ans;
    }
};