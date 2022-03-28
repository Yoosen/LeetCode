class Solution {
public:
    vector<int> track;
    vector<vector<int>> res;

    void backtrack(vector<int> nums, vector<bool>& used) {
        if(track.size() == nums.size() - 1) {
            res.push_back(track);
        }

        for(int i = 1; i < nums.size(); i++) {
            if(used[i] == true) continue;

            if(nums[i] % i == 0 || i% nums[i] == 0) {
                used[i] = true;
                track.push_back(nums[i]);

                backtrack(nums, used);

                track.pop_back();
                used[i] = false; 
            }
        }
    }

    int countArrangement(int n) {
        vector<int> nums;
        nums.push_back(0);

        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<bool> used(n + 1, false);

        return res.size();
    }
};