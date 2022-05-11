// LeetCode 32 最长有效括号

// 32. 最长有效括号
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

// 示例 1：

// 输入：s = "(()"
// 输出：2
// 解释：最长有效括号子串是 "()"
// 示例 2：

// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"
// 示例 3：

// 输入：s = ""
// 输出：0
 

// 提示：

// 0 <= s.length <= 3 * 10^4
// s[i] 为 '(' 或 ')'

class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> st;
    	st.push(-1);
    	int ans = 0;

    	for(int i = 0; i < s.length(); i++) {
    		// 当字符为'('，直接将下标入栈
    		if(s[i] == '(') {
    			st.push(i);
    		} else {
    			// 当字符为')'，先弹出栈顶元素，then 判断栈是否为空
    			st.pop();
    			if(!st.empty()) {
    				// 若此时栈不为空，说明配对成功，
    				// 然后用')'下标减去此时栈顶元素下标即为当前有效括号子串长度
    				ans = max(ans, i - st.top());
    			} else {
    				// 若此时栈为空（说明那个 -1 被弹出了），说明未配对成功，直接将')'下标入栈垫底
    				st.push(i);
    			}
    		}
    	}

    	return ans;
    }
};