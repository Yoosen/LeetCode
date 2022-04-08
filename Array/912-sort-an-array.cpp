// LeetCode 912 排序
// 手撕排序， 快排

// 使用随机函数，来随机选取pivot

class Solution {
	int randomized_partition(vector<int>& nums, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(nums[r], nums[i]);
		return partition(nums, l, r);
	}
	int partition(vector<int>& nums, int l, int r) {
		int pivot = nums[r];
		int i = l - 1;	// 双指针
		for(int j = l; j < r; j++) {
			if(nums[j] <= pivot) {
				i++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[r]); 	// 中轴的位置放上
		return i + 1;	// 返回中轴的位置
	}

	void randomized_quicksort(vector<int>& nums, int l, int r) {
		if(l < r) {
			int pos = randomized_partition(nums, l, r);
			randomized_quicksort(nums, l, pos - 1);
			randomized_quicksort(nums, pos + 1, r);
		}
	}
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};