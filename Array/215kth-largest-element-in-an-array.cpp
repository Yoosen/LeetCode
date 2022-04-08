// LeetCode 215 数组中的第K个最大元素
// 215. 数组中的第K个最大元素
// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。



// 示例 1:

// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4


// 提示：

// 1 <= k <= nums.length <= 104
// -104 <= nums[i] <= 104

class Solution {
public:
	// 向下调整
	void adjustDown(vector<int>& nums, int root, int length) {
		// 先取出当前元素 非叶节点 从下到上
		int temp = nums[root];

		for(int k = 2 * root; k < length; k *= 2) {
			// 取出左右节点中较大的一个节点
			if(k < length && nums[k] < nums[k + 1])
				k++;

			// 如果比两个子节点都大 
			if (temp >= nums[k]) break;

			// 较大子节点和根节点对比，交换
			nums[root] = nums[k];
			root = k;
		}
		nums[root] = temp;	// temp值放到最终的位置
	}

	//构建大根堆
	void buildMaxHeap(vector<int>& nums) {
		int n = nums.size();

		for(int root = n / 2; root > 0; root--) {
			adjustDown(nums, root, n);
		}
	}


	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		buildMaxHeap(nums);

		// 特判
		// if(n == 2 && k == 1)
		// 	return max(nums[0], nums[1]);
		// else if(n == 2 && k == 2)
		// 	return min(nums[0], nums[1]);

		for(int i = 0; i < k; i++) {
    		swap(nums[0], nums[n - 1 - i]);	// 堆顶和最后一个交换
    		adjustDown(nums, 0, n - 1 - i - 1);	// 继续调整剩下的节点
    	}
    	return nums[0];
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//     	int res, index;
//     	for(int i = 0; i < nums.size(); i++) {

//     		int index = i;

//     		for(int j = i + 1; j < nums.size(); j++) {
//     			if (nums[j] >= nums[index]) {
//     				index = j;
//     			}
//     		}

//     		swap(nums[i], nums[index]);


//     		res = nums[i];
//     		k--;

//     		wlengthle(k == 0) {
//     			return res;
//     		}
//     	}
//     	return nums[0];
//     }
// };