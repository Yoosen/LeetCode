// 647. 回文子串
// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

// 回文字符串 是正着读和倒过来读一样的字符串。

// 子字符串 是字符串中的由连续字符组成的一个序列。

// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

// 示例 1：

// 输入：s = "abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"
// 示例 2：

// 输入：s = "aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

// 提示：

// 1 <= s.length <= 1000
// s 由小写英文字母组成

class Solution {
public:
    int countSubstrings(string s) {
    	int res = 0;
    	int n = s.size();
 
    	// 中心点的个数 2 * n - 1
    	for(int i = 0; i < 2 * n - 1; ++i) {
    		int left = i / 2;
    		int right = i / 2 + i % 2;

    		// 要么left等于right，要么left+1等于right。也就是说如果left等于
        	// right，那么中心点就是一个字符，如果left+1等于right，中心点就是
        	// 2个字符
    		while(left >= 0 && right < n && s[left] == s[right]) {
    			res++;
    			left--;
    			right++;
    		}
    	}

    	return res;

    	// vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    	// for(int i = n - 1; i >= 0; --i) {
    	// 	for(int j = i; j < n; ++j) {
    	// 		if(s[i] == s[j]) {
    	// 			// 1.下标 i 与 j 相同，说明在区间内只有一个字符所以是回文子串即 dp[i][j] = true
					// // 2.下标 i 与 j 相差为 1，说明在区间内有两个相等的字符所以是回文子串即 dp[i][j] = true
    	// 			if(j - i < 2) {
    	// 				res++;
    	// 				dp[i][j] = true;
    	// 			}
    	// 			// 3.下标相差大于 1时，>= 2，要判断 dp[i + 1][j - 1]
    	// 			else if(dp[i + 1][j - 1]){
    	// 				res++;
    	// 				dp[i][j] = true;		// dp[i][j] = dp[i + 1][j - 1]
    	// 			}
    	// 		}
    	// 	}
    	// }
    }
};