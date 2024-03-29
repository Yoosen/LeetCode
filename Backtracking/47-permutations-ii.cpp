// 47. 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

// 示例 1：

// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// 示例 2：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// 提示：

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

class Solution {
public:
	vector<vector<int>> res;
	vector<int> track;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());

    	vector<bool> used(nums.size(), false);

    	backtrack(nums, used);

    	return res;
    }

    void backtrack(vector<int> nums, vector<bool>& used) {
    	if(track.size() == nums.size()) {
    		res.push_back(track);
    		return ;
    	}

    	for(int i = 0; i < nums.size(); ++i) {
    		if(used[i]) continue;

    		// 如果和前面一个数相同的话，那必须前面一个数已经用过了才能继续用，否则跳过
    		if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

    		used[i] = true;
    		track.push_back(nums[i]);

    		backtrack(nums, used);

    		track.pop_back();
    		used[i] = false;
    	}
    }
};