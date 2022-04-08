// LeetCode 15 三数之和
// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 示例 2：

// 输入：nums = []
// 输出：[]
// 示例 3：

// 输入：nums = [0]
// 输出：[]
 

// 提示：

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// 算法思想：
// 先排序方便去重，然后进行双指针查找

class Solution {
    // 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int> > vi;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return vi;

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if(nums[left] + nums[right] > target) right--;  // 三数相加大于 0， 右指针缩小
                else if(nums[left] + nums[right] < target) left++;  // 三数相加小于0，左指针增加
                else {  //三数相等，记录下来
                        vi.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]) left++;   // 去重
                        while(left < right && nums[right] == nums[right+1]) right--;    // 去重
                }
            }
        }
        return vi;
    }
};