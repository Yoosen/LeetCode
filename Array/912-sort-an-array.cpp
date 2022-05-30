// LeetCode 912 排序 堆排序实现

// 912. 排序数组
// 给你一个整数数组 nums，请你将该数组升序排列。

 

// 示例 1：

// 输入：nums = [5,2,3,1]
// 输出：[1,2,3,5]
// 示例 2：

// 输入：nums = [5,1,1,2,0,0]
// 输出：[0,0,1,1,2,5]
 

// 提示：

// 1 <= nums.length <= 5 * 10^4
// -5 * 10^4 <= nums[i] <= 5 * 10^4
// 手撕排序， 快排

// 使用随机函数，来随机选取pivot

class Solution {
	// int randomized_partition(vector<int>& nums, int l, int r) {
	// 	int i = rand() % (r - l + 1) + l;
	// 	swap(nums[r], nums[i]);
	// 	return partition(nums, l, r);
	// }
	// int partition(vector<int>& nums, int l, int r) {
	// 	int pivot = nums[r];
	// 	int i = l - 1;	// 双指针
	// 	for(int j = l; j < r; j++) {
	// 		if(nums[j] <= pivot) {
	// 			i++;
	// 			swap(nums[i], nums[j]);
	// 		}
	// 	}
	// 	swap(nums[i + 1], nums[r]); 	// 中轴的位置放上
	// 	return i + 1;	// 返回中轴的位置
	// }

	// void randomized_quicksort(vector<int>& nums, int l, int r) {
	// 	if(l < r) {
	// 		int pos = randomized_partition(nums, l, r);
	// 		randomized_quicksort(nums, l, pos - 1);
	// 		randomized_quicksort(nums, pos + 1, r);
	// 	}
	// }
	void adjust(vector<int>& nums, int k, int len) {

		int t = nums[k];	// 记录当前节点，寻找子孩子比自己大的子节点
		for(int i = 2 * k + 1; i < len; i = i * 2 + 1) {	// 由于堆顶元素下标为0，所以它的左孩子下标为2k+1=1
			if (i < len - 1 && nums[i] < nums[i + 1]) {		// i<len-1确保它右兄弟存在(数组中最后一个元素下标为len-1)
				i++;
			}

			if(t >= nums[i]) break;		// 如果tmp比它左右孩子要大，那么说明是对的，筛选结束。
			else {
				nums[k] = nums[i];		// 如果不是，那就把大的元素值放到k的位置
				k = i;					// 修改k的值，以当前i为根去继续筛选
			}
		}
		
		nums[k] = t;	// 把被筛选结点放入最终位置
	}


	void build(vector<int>& nums, int len) {
		for(int i = len / 2 - 1; i >= 0; i--) {
			adjust(nums, i, len);	//从 i = [n/2] ~ 0反复调整堆，从下到上，从右到右调整
		}
	}
public:
    vector<int> sortArray(vector<int>& nums) {
    	build(nums, nums.size());	// 先建立大根堆
    	for (int i = nums.size() - 1; i >= 0; i--) {
    		//交换堆顶元素（最大值）和堆底元素，再根据新的堆顶元素重新调整堆
    		swap(nums[i], nums[0]);
    		adjust(nums, 0, i);
    	}
    	return nums;
        // srand((unsigned)time(NULL));
        // randomized_quicksort(nums, 0, (int)nums.size() - 1);
        // return nums;
    }
};