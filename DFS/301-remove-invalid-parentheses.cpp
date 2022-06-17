// 301. 删除无效的括号
// 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

// 返回所有可能的结果。答案可以按 任意顺序 返回。

 

// 示例 1：

// 输入：s = "()())()"
// 输出：["(())()","()()()"]
// 示例 2：

// 输入：s = "(a)())()"
// 输出：["(a())()","(a)()()"]
// 示例 3：

// 输入：s = ")("
// 输出：[""]
 

// 提示：

// 1 <= s.length <= 25
// s 由小写英文字母以及括号 '(' 和 ')' 组成
// s 中至多含 20 个括号

// too hard

class Solution {		

private:
	int maxScore;
	int length;
	int n;
	unordered_set<string> hash;

public:
	vector<string> removeInvalidParentheses(string s) {
    	//假设“(”为+1分,")"为-1分，那么合规的字符串分数一定是0
        //分数一定不会是负数，因为那样意味着)比(多，不可能合规
        //分数一定不会超过maxscore，maxscore就是所有可匹配的(都在左边，一直+1，能达到的最大分数
		maxScore = 0;
		n = s.size();
		int left = 0, right = 0;	// 左右括号个数
		int l = 0, r = 0;
		length = 0;

		for(auto& c : s) {
			if(c == '(') {
				l++;
				left++;
			} else if(c == ')') {
				if(l != 0) l--;	// 去除相对应的右括号，多余的左括号
				else r++;	// 多余的右括号
				right++;
			}
		}  
		length = n - l - r;		// 删除多余的字符串以后，最后字符串应该有的长度

		maxScore = min(left, right);    // 可能得到的最大分数

		dfs(s, 0, "", l, r, 0);
		return {hash.begin(), hash.end()};  
	}

	// s : 源字符串
	// score : 当前分数
	// buf : 缓存
	// l : 多余的左括号数量, r : 多余的右括号数量, index : 当前遍历字符串的索引
	void dfs(const string& s, int score, string buf, int l, int r, int index) {
		if(l < 0 || r < 0 || score < 0 || score > maxScore) return ;

		// 满足需要的条件
		if(l == 0 && r == 0 && buf.length() == length) hash.insert(buf);

		if(index == n) return ;

		char ch = s[index];
		if(ch == '(') {
			dfs(s, score + 1, buf + '(', l, r, index + 1); //选择添加左括号，则+1分，继续遍历
            dfs(s, score, buf, l - 1, r, index + 1);//选择不添加左括号，相当于删除左括号，则分数不变，继续遍历
        } else if (ch == ')') {
        	dfs(s, score - 1, buf + ')', l, r, index + 1);//选择添加右括号，则-1分，继续遍历
            dfs(s, score, buf, l, r - 1, index + 1);//选择不添加右括号，相当于删除右括号，则分数不变，继续遍历
        } else {
        	dfs(s, score, buf + ch, l, r, index + 1);//遇到其他字符，直接添加，继续遍历
        }
    }
};