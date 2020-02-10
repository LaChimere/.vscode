#include "tools"
class Solution {
public:
    int climbStairs(int n) {
        // 递归
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // if (dp.find(n) != dp.end())
        //     return dp[n];
        // else {
        //     dp[n] = climbStairs(n-1) + climbStairs(n-2);
        //     return dp[n];
        // }

        //动态规划
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
// private:
//     unordered_map<int, int> dp;
};