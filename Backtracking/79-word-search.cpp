// LeetCode 79 单词搜索

// 79. 单词搜索
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

// 示例 1：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// 输出：true
// 示例 3：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// 输出：false
 

// 提示：

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成

class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
    	m = board.size();
        n = board[0].size();
    	int k = 0; 	// 记录当前单词索引

    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			if(backtrack(board, word, i, j, k))
    				return true;
    		}
    	}

    	return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k) {
    	// 边界条件
    	if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;

    	if(k == word.length() - 1) return true;

    	board[i][j] = '\0';

    	bool res = backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i - 1, j, k + 1) ||
    				backtrack(board, word, i, j + 1, k + 1) || backtrack(board, word, i, j - 1, k + 1);
    	board[i][j] = word[k];

    	return res;
    }
};