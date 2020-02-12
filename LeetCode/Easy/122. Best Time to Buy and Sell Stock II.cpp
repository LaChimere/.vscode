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
    }
};