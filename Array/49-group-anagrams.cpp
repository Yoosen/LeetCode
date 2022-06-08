// LeetCode 49 字母异位词分组

// 49. 字母异位词分组
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

 

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 示例 2:

// 输入: strs = [""]
// 输出: [[""]]
// 示例 3:

// 输入: strs = ["a"]
// 输出: [["a"]]
 

// 提示：

// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] 仅包含小写字母

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> res;		// 根据返回值定义存储结果的变量

    	unordered_map<string, vector<string>> m;

    	for(string& str : strs) {
    		string key = str;
    		/* 将串排序后便于同一作为键 */
    		sort(key.begin(), key.end());
    		/* 将相同键值的字符串放入vector容器中 */
    		m[key].push_back(str);
    	}

    	/* 取出相同键值的vector */
    	for(auto it = m.begin(); it != m.end(); ++it) {
    		res.push_back(it->second);
    	}

    	return res;
    }
};