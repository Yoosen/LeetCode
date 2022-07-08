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

        int x = rand() % (r - l + 1) + l;	// 随机选取 [l, r] 区间的点

        swap(nums[l], nums[x]);
        int pivot = nums[l];

        int left = l, right = r;

        while(left < right) {
            // 从后往前走，将比第一个小的移到前面
            while(left < right && nums[right] >= pivot) --right;
            if(left < right) {
                // nums[left]已保存，直接覆盖
                nums[left] = nums[right];
            }

            // 从前往后走，将比第一个大的移到后面
            while(left < right && nums[left] <= pivot) ++left;
            if(left < right) {
                nums[right] = nums[left];
            }
        }

        nums[left] = pivot;
        quickSort(nums, l, left - 1);
        quickSort(nums, left + 1, r);
    }
};