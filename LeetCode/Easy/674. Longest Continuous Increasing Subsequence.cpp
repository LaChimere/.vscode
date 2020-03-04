#include "tools"
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1;
        int left = 0, right;
        for (right = 0; right < nums.size(); right++) {
            if (right < nums.size() - 1 && nums[right + 1] > nums[right]) continue;
            if (right == nums.size() - 1) break;
            maxLen = max(right - left + 1, maxLen);
            left = right + 1;
        }
        maxLen = max(right - left + 1, maxLen);
        return maxLen;
    }
};