// LeetCode 227 基本计算器 II

// 227. 基本计算器 II
// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

// 整数除法仅保留整数部分。

// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内。

// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

 

// 示例 1：

// 输入：s = "3+2*2"
// 输出：7
// 示例 2：

// 输入：s = " 3/2 "
// 输出：1
// 示例 3：

// 输入：s = " 3+5 / 2 "
// 输出：5
 

// 提示：

// 1 <= s.length <= 3 * 105
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
// s 表示一个 有效表达式
// 表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
// 题目数据保证答案是一个 32-bit 整数

class Solution {
public:
    stack<int> nums;
    stack<char> ops;

    void calc() {
    	int b = nums.top(); nums.pop();
    	int a = nums.top(); nums.pop();

    	char c = ops.top(); ops.pop();

    	int r;
    	if(c == '+') r = a + b;
    	else if(c == '-') r = a - b;
    	else if(c == '*') r = a * b;
    	else r = a / b;

    	nums.push(r);
    }

    int calculate(string s) {
    	s = "0" + s;
    	unordered_map<char, int> m;
    	m['+'] = m['-'] = 1;
    	m['*'] = m['/'] = 2;

    	for(int i = 0; i < s.length(); i++) {
    		char c = s[i];
    		if(c == ' ') continue;
    		if(isdigit(c)) {
    			int x = 0;
    			while(i < s.length() && isdigit(s[i]))
    				x = x * 10 + (s[i++] - '0');
    			nums.push(x);
    			i--;
    		}
    		else {
    			//ops栈非空并且栈顶操作符优先级大于等于当前操作符c的优先级，进行eval()计算
    			while(ops.size() && m[ops.top()] >= m[c]) calc();
    			// 否则，压栈
    			ops.push(c);
    		}
    	}

    	while(ops.size()) calc();
    	return nums.top();
    }
};