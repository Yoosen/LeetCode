// 5. 最长回文子串
// 给你一个字符串 s，找到 s 中最长的回文子串。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
 

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成

// 中心扩散法

class Solution {
public:
    string longestPalindrome(string s) {
    	int start = 0, end = 0;

    	for(int i = 0; i < s.length(); ++i) {
    		int len1 = expand(s, i, i);
    		int len2 = expand(s, i, i + 1);
    		int len = max(len1, len2);

    		if(len > end - start) {
    			start = i - (len - 1) / 2;
    			end = i + len / 2;
    		}
    	}

    	return s.substr(start, end - start + 1);
    }

    int expand(string s, int left, int right) {
    	int L = left, R = right;

    	while(L >= 0 && R < s.length() && s[L] == s[R]) {
    		L--;
    		R++;
    	}

    	return R - L - 1;
    }
};