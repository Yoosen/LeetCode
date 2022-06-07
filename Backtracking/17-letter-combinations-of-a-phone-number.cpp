// LeetCode 17 电话号码的字母组合

// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

// 示例 1：

// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：

// 输入：digits = ""
// 输出：[]
// 示例 3：

// 输入：digits = "2"
// 输出：["a","b","c"]
 

// 提示：

// 0 <= digits.length <= 4
// digits[i] 是范围 ['2', '9'] 的一个数字。

class Solution {
public:
	vector<string> res;
	string track;
	vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0) return res;
    	backtrack(0, digits);
    	return res;
    }

    void backtrack(int pos, string digits) {
    	if(pos == digits.size()) {
    		res.push_back(track);
    		return;
    	}

    	int num = digits[pos] - '0';
    	for(int i = 0; i < board[num].size(); i++) {
    		track.push_back(board[num][i]);
    		backtrack(pos + 1, digits);
    		track.pop_back();
    	}
    }
};