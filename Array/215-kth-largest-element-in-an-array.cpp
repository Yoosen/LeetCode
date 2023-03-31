// 215. 数组中的第K个最大元素
// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1:

// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4
 

// 提示：

// 1 <= k <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto n : nums) {

            // 如果队列已经有k个元素，大于当前k个元素的小顶堆才可以进入
            if(pq.size() == k && pq.top() >= n) continue;

            if(pq.size() == k)
                pq.pop();

            pq.push(n);
        }

        return pq.top();
    }
};