class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

    	// 对数组遍历，只让在 i 放上 i + 1
    	for(int i = 0; i < nums.size(); i++) {
    		while(nums[i] != i + 1) {
    			if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) 
    				break;
    			int idx = nums[i] - 1;
    			nums[i] = nums[idx];
    			nums[idx] = idx + 1;
    		}
    	}

    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] != (i + 1))
    			return i + 1;
    	}

    	return nums.size() + 1;
    }
};