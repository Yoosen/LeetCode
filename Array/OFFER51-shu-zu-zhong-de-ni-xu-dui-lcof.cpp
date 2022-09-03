// 剑指 Offer 51. 数组中的逆序对
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

// 示例 1:

// 输入: [7,5,6,4]
// 输出: 5 

// 限制：

// 0 <= 数组长度 <= 50000

class Solution {
public:
    // dp[i] 表示包括第 i 位的逆序对总数
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }

    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
        // 终止条件
        if(l >= r) return 0;
        // 递归划分
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m + 1;

        // [l, r] 区间拷贝下来进行排序
        for(int k = l; k <= r; ++k) {
            tmp[k] = nums[k];
        }

        for(int k = l; k <= r; ++k) {
            // 1.当 i = m + 1时：代表左子数组已合并完
            // 因此添加右子数组当前元素 tmp[j] ，并执行 j = j + 1
            if(i == m + 1)
                nums[k] = tmp[j++];
            // 2.否则，当 j = r + 1 时： 代表右子数组已合并完，因此添加左子数组当前元素 tmp[i]，并执行 i = i + 1；
            // 3.否则，当 tmp[i] <= tmp[j] 时： 添加左子数组当前元素 tmp[i] ，并执行 i = i + 1；
            else if(j == r + 1 || tmp[i] <= tmp[j]) {
                nums[k] = tmp[i++];
            }
            // 4.否则（即 tmp[i] > tmp[j]）时：添加右子数组当前元素 tmp[j] ，并执行 j = j + 1；
            // 此时构成 m - i + 1 个「逆序对」，统计添加至 res
            else {
                nums[k] = tmp[j++];

                res += m - i + 1;
            }
        }
        return res;
    }
};