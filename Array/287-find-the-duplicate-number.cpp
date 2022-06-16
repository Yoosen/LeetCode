// 287. 寻找重复数
// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

 

// 示例 1：

// 输入：nums = [1,3,4,2,2]
// 输出：2
// 示例 2：

// 输入：nums = [3,1,3,4,2]
// 输出：3
 

// 提示：

// 1 <= n <= 10^5
// nums.length == n + 1
// 1 <= nums[i] <= n
// nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 

// 进阶：

// 如何证明 nums 中至少存在一个重复的数字?
// 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？

// 快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int slow = 0, fast = 0;

    	slow = nums[slow];
    	fast = nums[nums[fast]];

    	while(fast != slow) {
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}

    	slow = 0;
    	while(slow != fast) {
    		slow = nums[slow];
    		fast = nums[fast];
    	}

    	return slow;
    }
};


// // 进行异或，处理此题错误，仅能处理数组内仅有一个重复数
// // 异或性质 ： 
// // 1.n ^ n = 0
// // 2. n ^ 0 = n
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//     	int tmp1 = 0, tmp2 = 0;
//     	for(int num : nums) {
//     		// 数组内进行异或，因为有重复，根据性质，异或出来的结果不包括重复数，记为 T
//     		tmp1 ^= num;
//     	}

//     	for(int i = 1; i <= nums.size(); ++i) {
//     		tmp2 ^= i;		// 这一句异或 1,2, ..., n 包括 d(重复数)，记为 T ^ d
//     	}

//     	return tmp1 ^ tmp2;	// T ^ (T ^ d) = d; 重复数
//     }
// };