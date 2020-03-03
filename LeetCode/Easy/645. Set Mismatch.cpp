#include "tools"
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0, dup = 0, len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            else dup = abs(nums[i]);
            sum += abs(nums[i]);
        }
        int realSum = (1 + len) * len / 2;
        return {dup, dup - (sum - realSum)};
        
        // int len = nums.size();
        // int realSum = (1 + len) * len / 2;
        // sort(nums.begin(), nums.end());
        // int sum = 0, repeatNum;
        // for (int i = 0; i < len - 1; i++) {
        //     sum += nums[i];
        //     if (nums[i] == nums[i + 1]) repeatNum = nums[i];
        // }
        // sum += nums[len - 1];
        // int diff = sum - realSum;
        // int lossNum = repeatNum - diff;
        // return {repeatNum, lossNum};
    }
};