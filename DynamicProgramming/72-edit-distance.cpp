// LeetCode 72 编辑距离

// 72. 编辑距离
// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
 

// 示例 1：

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2：

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')
 

// 提示：

// 0 <= word1.length, word2.length <= 500
// word1 和 word2 由小写英文字母组成

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int m = word1.length(), n = word2.length();

    	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    	// word2为空，只能删除
    	for(int i = 0; i <= m; ++i) {
    		dp[i][0] = i;
    	}
    	// word1为空，只能增加
    	for(int j = 0; j <= n; ++j) {
    		dp[0][j] = j;
    	}

    	for(int i = 1; i <= m; ++i) {
    		for(int j = 1; j <= n; ++j) {
    			if(word1[i - 1] == word2[j - 1]) {
    				dp[i][j] = dp[i - 1][j - 1];
    			}
    			else {
    				// 分别对应删除、插入和替换
    				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
    			}
    		}
    	}

    	return dp[m][n];
    }
};

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//     	int m = word1.length(), n = word2.length();
//     	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

//     	// 第一列
//     	for(int i = 1; i <= m; i++) {
//     		dp[i][0] = i;
//     	}

//     	// 第一行
//     	for(int j = 1; j <= n; j++) {
//     		dp[0][j] = j;
//     	}

//     	for(int i = 1; i <= m; i++) {
//     		for(int j = 1; j <= n; j++) {
//     			if(word1[i - 1] == word2[j - 1]) {
//     				// 如果前一个元素相同，那就不用采取任何操作
//     				dp[i][j] = dp[i - 1][j - 1];
//     			}

//     			else {
//     				// 三种可能，替换、删除、插入
//     				dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
//     			}
//     		}
//     	}
//     	return dp[m][n];
//     }
// };