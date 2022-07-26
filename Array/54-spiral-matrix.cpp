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
    	vector<int> res;

    	int top = 0;		// 当前上边界
    	int bottom = matrix.size() - 1;	 // 当前下边界
    	int left = 0;		// 当前左边界
    	int right = matrix[0].size() - 1;	//当前右边界

    	while(true) {
    		// 左到右
    		for(int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
    		++top;
    		if(top > bottom) break;

    		// 上到下
    		for(int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
    		--right;
    		if(right < left) break;

			// 右到左
    		for(int i = right; i >= left; --i) res.push_back(matrix[bottom][i]);
    		--bottom;
    		if(bottom < top) break;

    		// 下到上
    		for(int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
    		++left;
    		if(right < left) break;
    	}

    	return res;
    }
};