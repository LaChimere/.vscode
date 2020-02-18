#include "tools"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++)
            missing ^= i ^ nums[i];
        return missing;
        
        // math
        // int sum = (1 + nums.size()) * nums.size() / 2;
        // int realSum = 0;
        // for (int i = 0; i < nums.size(); i++)
        //     realSum += nums[i];
        // return sum - realSum;
        
        // vector<bool> isMissing(nums.size() + 1, true);
        // for (int i = 0; i < nums.size(); i++) {
        //     isMissing[nums[i]] = false;
        // }
        // for (int i = 0; i < isMissing.size(); i++)
        //     if (isMissing[i])
        //         return i;
        // return -1;
    }
};