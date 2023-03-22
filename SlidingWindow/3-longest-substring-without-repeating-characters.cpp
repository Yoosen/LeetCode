// LeetCode 3. 无重复字符的最长子串
// 中等
// 8.9K
// 相关企业
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

// 提示：

// 0 <= s.length <= 5 * 10^4
// s 由英文字母、数字、符号和空格组成

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_map<char, int> window;

    	int left = 0, right = 0;
    	int len = s.length();

    	int ans = 0;

    	while(right < len) {
    		char c = s[right];
    		right++;

    		window[c]++;
    		while(window[c] > 1) {
    			char d = s[left];

    			left++;
    			window[d]--;
    		}

    		ans = max(ans, right - left);
    	}
    	return ans;
    }
};