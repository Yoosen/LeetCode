// 77. 组合
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

// 示例 1：

// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// 示例 2：

// 输入：n = 1, k = 1
// 输出：[[1]]

class Solution {
public:

	vector<vector<int>> res;
	vector<int> track;
    
    void backtrack(int start, int n, int k) {
    	if(k == track.size()) {
    		res.push_back(track);
    	}

    	for(int i = start; i <= n; i++) {
    		track.push_back(i);

    		backtrack(i + 1, n, k);

    		track.pop_back();
    	}
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }
};