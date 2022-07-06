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

// 1 <= k <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4

// 无论怎么写，总有无法通过的个别用例

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	int n = nums.size();
    	buildHeap(nums);

    	// 调整 k - 1 次
    	for(int i = 0; i < k - 1; ++i) {
    		swap(nums[0], nums[n - 1 - i]);	// 最大的和最后一个交换位置
    		adjustDown(nums, 0, n - 1 - i);	// 重新调整剩下的元素
    	}
    	return nums[0];
    }

    // 自下到上建堆
    void buildHeap(vector<int>& nums) {
    	int n = nums.size();

    	for(int root = n / 2; root >= 0; --root) {
    		adjustDown(nums, root, n);
    	}
    }

    // 自上到下调整
    void adjustDown(vector<int>& nums, int root, int length) {
    	// 先取出当前元素 非叶节点 从下到上
    	int temp = nums[root];

    	// 寻找合适的位置放置
    	for(int k = root * 2 + 1; k < length; k *= 2) {
    		// 取出左右节点中较大的一个节点
    		if(k + 1 < length && nums[k] < nums[k + 1])
    			k++;

    		// 如果比两个子节点都大 
    		if(temp >= nums[k]) break;

    		// 较大子节点和根节点对比，交换
    		nums[root] = nums[k];
    		root = k;
    	}
    	nums[root] = temp;
    }

};