#include "tools"
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        int max1 = INT_MIN, max2 = INT_MIN, index = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] > max1) {max2 = max1; max1 = nums[i]; index = i;}
            else if (nums[i] > max2) max2 = nums[i];
        }
        return max1 >= 2 * max2 ? index : -1;
    }
};