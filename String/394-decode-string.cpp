// LeetCode 394 字符串解码

// 394. 字符串解码
// 给定一个经过编码的字符串，返回它解码后的字符串。

// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

// 示例 1：

// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
// 示例 2：

// 输入：s = "3[a2[c]]"
// 输出："accaccacc"
// 示例 3：

// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
// 示例 4：

// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"
 

// 提示：

// 1 <= s.length <= 30
// s 由小写英文字母、数字和方括号 '[]' 组成
// s 保证是一个 有效 的输入。
// s 中所有整数的取值范围为 [1, 300] 

class Solution {
public:
    string decodeString(string s) {
    	stack<int> nums;
    	stack<string> strs;

    	string res = "";	// res 是最上层的结果
    	int num = 0;
    	for(int i = 0; i < s.length(); i++) {
    		if(s[i] <= '9' && s[i] >= '0') {
    			num = num * 10 + (s[i] - '0');
    		}
    		else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
    			res += s[i];
    		}
    		else if(s[i] == '[') {
    			nums.push(num);
    			num = 0;
    			strs.push(res);
    			res = "";
    		}
    		else {
    			int times = nums.top();
    			nums.pop();

    			// a2[c] -> acc
    			for(int j = 0; j < times; j++) {
    				strs.top() += res;
    			}

    			// 3[a2[2[c]b]] -> 3[a2[ccb]] -> 3[accbccb] -> accbccbaccbccbaccbccb
    			res = strs.top(); //之后若还是字母，就会直接加到 res 之后，因为它们是同一级的运算
                                  //若是左括号，res 会被压入 strs 栈，作为上一层的运算
                strs.pop();
    		}
    	}

    	return res;

    	// int i = 0;
    	
    	// while(i < s.length()) {
    	// 	string curStr = "";
    	// 	int curNum = 0;

    	// 	if(s[i] != ']') {
    	// 		st.push(s[i]);
    	// 	}
    	// 	else {
    	// 		while(!st.empty() && st.top() !='[') {
    	// 			curStr += st.top();
    	// 			st.pop();
    	// 		}

    	// 		int j = 0;	// 位数
    	// 		while(!st.empty() && st.top() >= '0' && st.top() <= '9') {
    	// 			curNum = st.top() * pow(10, j) + curNum;
    	// 			j++;
    	// 			st.pop();
    	// 		}

    	// 		string temp = "";
    	// 		for(int k = 0; k < curNum; k++) {
    	// 			temp += curStr;
    	// 		}

    	// 		// 字符串栈放入字符串
    	// 		st.push(temp);
    	// 	}
    	// 	i++;
    	// }
    	// return st.top();
    }
};