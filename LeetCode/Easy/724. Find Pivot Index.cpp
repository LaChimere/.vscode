#include "tools"
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1) return 0;
        int sum = 0;
        for (int num : nums) sum += num;
        int i = 0;
        int leftSum = 0, rightSum = sum - leftSum - nums[i];
        while (i < len) {
            if (leftSum == rightSum) return i;
            leftSum += nums[i++];
            if (i < len) rightSum -= nums[i];
        }
        return -1;
    }
};