#include "tools"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Greedy Algorithm
        int max_profit = 0;
        if (!prices.empty()) {
            for (int i = 0; i < prices.size() - 1; i++) {
                if (prices[i] < prices[i + 1])
                    max_profit += prices[i + 1] - prices[i];
            }
        }
        return max_profit;
        
        // Dynamic Programming
        // int n = prices.size();
        // if (n < 2) return 0;
        // vector<vector<int>> dp(n);
        // dp[0].push_back(0);
        // dp[0].push_back(-prices[0]);
        // for (int i = 1; i < n; i++) {
        //     dp[i].push_back(max(dp[i - 1][0], dp[i - 1][1] + prices[i]));
        //     dp[i].push_back(max(dp[i - 1][1], dp[i - 1][0] - prices[i]));
        // }
        // return dp[n - 1][0];
    }
};