// LeetCode 75 颜色分类

// 75. 颜色分类
// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

// 必须在不使用库的sort函数的情况下解决这个问题。

 

// 示例 1：

// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]
// 示例 2：

// 输入：nums = [2,0,1]
// 输出：[0,1,2]
 

// 提示：

// n == nums.length
// 1 <= n <= 300
// nums[i] 为 0、1 或 2

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;

		///一次循环，两个指针分三个区，每次把元素放在三个区；
        //[0, l)存放0
        //[l, r]存放1
        //(r, n-1]存放2
		for(int i = 0; i <= r; ++i) {
			while(i <= r && nums[i] == 2) {
				swap(nums[i], nums[r]);
				r--;
			}

			if(nums[i] == 0) {
				swap(nums[l], nums[i]);
				l++;
			}
		}

	}
};