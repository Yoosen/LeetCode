// LeetCode 14 最长公共前缀

// 14. 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

 

// 示例 1：

// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
// 示例 2：

// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。
 

// 提示：

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] 仅由小写英文字母组成

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 1) return strs[0];
    	string tmp = strs[0];
    	for(int i = 1; i < strs.size(); i++) {
    		tmp = compare(tmp, strs[i]);
    		if(tmp == "")
    			return "";
    	}
    	return tmp;
    }

    string compare(string s1, string s2) {
    	int len = min(s1.length(), s2.length());
    	int index = 0;

    	for(int i = 0; i < len; i++) {
    		if(s1[i] == s2[i])
    			index++;
    		else
    			break;
    	}

    	return s1.substr(0, index);
    }
};