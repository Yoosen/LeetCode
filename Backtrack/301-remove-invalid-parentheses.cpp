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

class Solution {
private:
    int maxScore;
    int len;
    int n;
    string str;
    unordered_set<string> hash;

public:
    vector<string> removeInvalidParentheses(string s) {
        str = s;
        n = str.length();
        int l = 0, r = 0;
        int length = 0;

        for(auto& c : s) {
            if(c == '(') {
                l++;
            } else if(c == ')') {
                r++;
            }
        }

        maxScore = min(l, r);

        dfs(0, "", 0);

        return {hash.begin(), hash.end()};
    }

    void dfs(int u, string cur, int score) {
        if(score < 0 || score > maxScore) return ;

        if(u == n) {
        	// 总得分为0括号才匹配，当前路径长度 >= 最大路径子串的长度才记录或者更新
            if(score == 0 && cur.length() >= len) {
            	// 当前路径长度大于最大路径子串的长度时，说明有更长的合法串，清除set
                if(cur.length() > len) hash.clear();
                // 更新最大路径子串长度为当前路径长度，并且添加进集合
                len = cur.length();
                hash.insert(cur);
            }
            return ;
        }

        char c = str[u];
        if(c == '(') {
            dfs(u + 1, cur + "(", score + 1);
            dfs(u + 1, cur, score);
        } else if(c == ')') {
            dfs(u + 1, cur + ")", score - 1);
            dfs(u + 1, cur, score);
        } else {
        	dfs(u + 1, cur + c, score);
        }
    }
};