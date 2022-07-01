// LeetCode 1143. 最长公共子序列 原题

// 【求最长公共子序列的长度】
// 问题描述: 
// 给定两个字符串str1和str2，输出两个字符串的最长公共子序列的长度。如果最长公共子序列为空，则返回"0"。目前给出的数据，仅仅会存在 一个最长的公共子序列 

// 输入描述: 
// 1
// 输入: "1A2C3D4B56","B1D23A456A" 

// 输出描述: 
// 1
// 输出: 6 

// 输入样例: 
// 1
// 2
// 1A2C3D4E56 
// A1B2345C6D 
// 输出样例:
//  6 

int longestCommonSubsequence(string text1, string text2) {
	int m = text1.length();
	int n = text2.length();

	// dp[i][j] 代表text1[0:i-1] 与 text2[0:j-1]之间的最长公共子序列
	// 所以需要看text[i]与text2[j]是否相同
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for(int i = 1; i <= m; ++i) {
		char c = text1[i];

		for(int j = 1; j <= n; ++j) {
			char d = text2[j];

			if(c == d) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[m][n];
}