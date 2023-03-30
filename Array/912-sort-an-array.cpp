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

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if(l >= r) return ;

        int x = rand() % (r - l + 1) + l;
        int pivot = nums[x];

        int i = l - 1, j = r + 1;
        while(i < j) {
            while(nums[++i] < pivot);
            while(nums[--j] > pivot);
            if(i < j) swap(nums[i], nums[j]);
        }

        quickSort(nums, l, j);
        quickSort(nums, j + 1, r);
    }
};