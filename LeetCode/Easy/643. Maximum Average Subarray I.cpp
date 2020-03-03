#include "tools"
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int preSum = 0;
        for (int i = 0; i < k; i++) preSum += nums[i];
        int maxSum = preSum;
        for (int i = k; i < len; i++) {
            int curSum = preSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, curSum);
            preSum = curSum;
        }
        return (double)maxSum / k;
    }
};