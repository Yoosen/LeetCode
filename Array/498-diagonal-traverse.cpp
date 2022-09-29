// 498. 对角线遍历
// 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

// 示例 1：

// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,4,7,5,3,6,8,9]
// 示例 2：

// 输入：mat = [[1,2],[3,4]]
// 输出：[1,2,3,4]
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10^4
// 1 <= m * n <= 10^4
// -10^5 <= mat[i][j] <= 10^5

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        if(mat.empty() || mat[0].empty()) return res;
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n + m - 1; ++i) {
            if(i % 2 == 0) {	//偶数对角线，左下到右上
                for(int x = min(i, n - 1); x >= max(0, i - m + 1); x--)		//从下往上遍历
                    res.push_back(mat[x][i - x]);
            } else {			//奇数对角线，右上到左下
                for (int x = max(0,  i - m + 1); x <= min(i, n - 1); x++)	//从上往下遍历
                    res.push_back(mat[x][i - x]);
            }
        }

        return res;
    }
};