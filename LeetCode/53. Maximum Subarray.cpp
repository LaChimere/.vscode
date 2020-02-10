#include "tools"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }
        int sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] > sum)
                sum = dp[i];
        }
        return sum;
    }
};