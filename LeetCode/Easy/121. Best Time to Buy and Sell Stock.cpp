#include "tools"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Dynamic Programming
        int min_price = INT_MAX, max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) min_price = prices[i];
            else if (prices[i] - min_price > max_profit)
                max_profit = prices[i] - min_price;
        }
        return max_profit;
    }
};