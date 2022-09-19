// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]
 

// 提示：

// 1 <= n <= 8

class Solution {
public:

    /**
     * @param curStr 当前递归得到的结果
     * @param left   左括号已经用了几个
     * @param right  右括号已经用了几个
     * @param n      左括号、右括号一共得用几个
     * @param res    结果集
     */
    void backtrack(string curStr, int left, int right, int n, vector<string>& res) {
    	if(left == n && right == n) {
    		res.emplace_back(curStr);
    		return ;
    	}

    	if(left < right) {
    		return ;
    	}

    	if(left < n) {
    		backtrack(curStr + "(", left + 1, right, n, res);
    	}

    	if(right < n) {
    		backtrack(curStr + ")", left, right + 1, n, res);
    	}
    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;

        if(n == 0) {
            return res;
        }

        backtrack("", 0, 0, n, res);

        return res;
    }
};