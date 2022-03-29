// LeetCode 79 & 剑指 Offer 12题

// 赞最高者的答案

// 算法思想
// 深度优先遍历（DFS） + 剪枝；

// 递归参数： 当前元素在矩阵 board 中的行列索引 i 和 j ，当前目标字符在 word 中的索引 k 。

// 终止条件：
// 返回 false ： (1) 行或列索引越界 或 (2) 当前矩阵元素与目标字符不同 或 (3) 当前矩阵元素已访问过 （ (3) 可合并至 (2) ） 。
// 返回 true ： k = len(word) - 1 ，即字符串 word 已全部匹配。

// 递推工作：
// 标记当前矩阵元素： 将 board[i][j] 修改为 空字符 '' ，代表此元素已访问过，防止之后搜索时重复访问。
// 搜索下一单元格： 朝当前元素的 上、下、左、右 四个方向开启下层递归，使用 或 连接 （代表只需找到一条可行路径就直接返回，不再做后续 DFS ），并记录结果至 res 。
// 还原当前矩阵元素： 将 board[i][j] 元素还原至初始值，即 word[k] 。

class Solution {
public:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
    	
    	// 终止条件
        if(i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
        	return false;
        if(k == word.size() - 1) return true;

        // 回溯
        board[i][j] = '\0';
        // 四个方向遍历
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) ||
        			dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
            	if(dfs(board, word, i, j, 0))
            		return true;
            }
        }

        return false;
    }
};