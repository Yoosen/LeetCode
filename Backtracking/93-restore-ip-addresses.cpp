// LeetCode 93 复原 IP 地址

// 93. 复原 IP 地址
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 

// 示例 1：

// 输入：s = "25525511135"
// 输出：["255.255.11.135","255.255.111.35"]
// 示例 2：

// 输入：s = "0000"
// 输出：["0.0.0.0"]
// 示例 3：

// 输入：s = "101023"
// 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// 提示：

// 1 <= s.length <= 20
// s 仅由数字组成

class Solution {
public:
	vector<string> res;
	vector<string> track;

    vector<string> restoreIpAddresses(string s) {
    	if(s.length() > 12 || s.length() < 4) return res;

    	backtrack(s, 0, track);

    	return res;
    }

    void backtrack(string s, int start, vector<string>& track) {
    	// 如果字符串刚好用完 且 track 的大小为 4，即合法 IP 地址
    	if(start == s.length() && track.size() == 4) {
    		string temp = "";
    		for(int i = 0; i < 4; i++) {
    			if(i == 0) temp += track[i];
    			else temp = temp + "." + track[i];
    		}
    		res.push_back(temp);
    		return ;
    	}

    	for (int i = start; i < start + 3 && i < s.length(); i++) {
    		// 剪枝掉第一位为 0 的情况，如 011 等
    		if(i != start && s[start] == '0') continue;
    		// 这个剪枝为实时判断剩下的字符串长度是否超过最大所需长度
    		if(s.length() - i > 3 * (4 - track.size())) continue;
    		string str = s.substr(start, i - start + 1);
    		int t = stoi(str);
    		if(t > 255) continue;

    		track.push_back(str);
    		backtrack(s, i + 1, track);
    		track.pop_back();
    	}
    }
};