// 剑指 Offer 49. 丑数
// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

// 示例:

// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 说明:  

// 1 是丑数。
// n 不超过1690。

class Solution {
public:
    int nthUglyNumber(int n) {
    	vector<int> dp(n + 1);

    	dp[1] = 1;
    	int p2 = 1, p3 = 1, p5 = 1;
    	for(int i = 2; i <= n; ++i) {
    		int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
    		dp[i] = min(min(num2, num3), num5);

    		if(dp[i] == num2)
    			p2++;
    		if(dp[i] == num3)
    			p3++;
    		if(dp[i] == num5)
    			p5++;
    	}

    	return dp[n];
    }
};