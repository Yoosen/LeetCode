// LeetCode 718 最长重复子数组

// 718. 最长重复子数组
// 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

 

// 示例 1：

// 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// 输出：3
// 解释：长度最长的公共子数组是 [3,2,1] 。
// 示例 2：

// 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// 输出：5
 

// 提示：

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size();
    	int n = nums2.size();
    	int ans = 0;

    	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    	for(int i = 1; i <= m; i++) {
    		int t1 = nums1[i - 1];
    		for(int j = 1; j <= n; j++) {
    			int t2 = nums2[j - 1];
    			if(t1 == t2)
    				dp[i][j] = 1 + dp[i - 1][j - 1];
    			else
    				dp[i][j] = 0;

    			ans = max(ans, dp[i][j]);
    		}
    	}

    	return ans;
    }
};