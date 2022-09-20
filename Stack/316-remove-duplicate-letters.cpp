// 316. 去除重复字母
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

 

// 示例 1：

// 输入：s = "bcabc"
// 输出："abc"
// 示例 2：

// 输入：s = "cbacdcbc"
// 输出："acdb"
 

// 提示：

// 1 <= s.length <= 10^4
// s 由小写英文字母组成

class Solution {
public:
    string removeDuplicateLetters(string s) {

    	// 维护一个计数器记录字符串中字符的数量
    	unordered_map<int, int> mp;
    	for(char c : s) {
    		mp[c]++;
    	}

    	stack<char> stk;
    	// 记录该字符是否已在栈中
    	unordered_map<char, bool> inStack;
    	for(char c : s) {
			// 每遍历过一个字符，都将对应的计数减一
    		mp[c]--;

    		if(inStack[c]) continue;

    		while(!stk.empty() && stk.top() > c) {
    			// 若之后不存在栈顶元素了，则停止 pop
    			if(mp[stk.top()] == 0) {
    				break;
    			}
    			inStack[stk.top()] = false;
    			stk.pop();
    		}

    		stk.push(c);
    		inStack[c] = true;
    	}

    	string res = "";
    	while(!stk.empty()) {
    		res += stk.top();
    		stk.pop();
    	}

    	reverse(res.begin(), res.end());
    	return res;
    }
};