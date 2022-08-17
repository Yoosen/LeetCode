// 131. 分割回文串
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

 

// 示例 1：

// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
// 示例 2：

// 输入：s = "a"
// 输出：[["a"]]
 

// 提示：

// 1 <= s.length <= 16
// s 仅由小写英文字母组成

class Solution {
private:
	vector<vector<string>> res;
	vector<string> path;

	void backtrack(const string& s, int start) {
		if(start >= s.length()) {
			res.push_back(path);
			return ;
		}

		for(int i = start; i < s.length(); ++i) {
			if(isPalindrome(s, start, i)) {
				string substr = s.substr(start, i - start + 1);
				path.push_back(substr);
			} else {
				continue;
			}

			backtrack(s, i + 1);	// 寻找 i+1 为起始位置的子串
			path.pop_back();
		}
	}

    bool isPalindrome(const string& s, int start, int end) {
        int left = start, right = end;

        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
    	res.clear();
    	path.clear();
    	backtrack(s, 0);

    	return res;
    }
};