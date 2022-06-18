// 309. 最佳买卖股票时机含冷冻期
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

// 示例 1:

// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
// 示例 2:

// 输入: prices = [1]
// 输出: 0
 

// 提示：

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

// dp
// dp[i][0]  当前没有持有股票，可能因为昨天也没持有；也可能因为昨天持有，今天卖了 收益 +prices[i]
// dp[i][1]  当前持有股票，可能因为昨天也持有；也可能因为昨天冷冻期，昨天之前的收益 - 今天刚买的，就是当前收益

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();

    	vector<vector<int>> dp(n, vector<int>(2));

    	for(int i = 0; i < n; ++i) {
    		if(i == 0) {
    			dp[i][0] = 0;
    			dp[i][1] = -prices[i];
    			continue;
    		}
    		if(i == 1) {
    			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    			dp[i][1] = max(dp[i - 1][1], -prices[i]);
    			continue;
    		}

    		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    		dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    	}

    	return dp[n - 1][0];
    }
};