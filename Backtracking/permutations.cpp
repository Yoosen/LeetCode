// 46. 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

#include<bits/stdc++.h>
using namespace std;

vector<int> track;
vector<vector<int>> res;

void backtrack(vector<int> nums, vector<bool>& used){

	if(track.size() == nums.size()) {
		res.push_back(track);
		return ;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if(used[i] == true) continue;

		used[i] = true;
		track.push_back(nums[i]);

		backtrack(nums, used);

		track.pop_back();
		used[i] = false;
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	res.clear();
	track.clear();
	vector<bool> used(nums.size(), false);

	backtrack(nums, used);

	return res;
}

int main()
{
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> ans = permute(nums);
	for (int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < ans[0].size(); j++) {
            printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
