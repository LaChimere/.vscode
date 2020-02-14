#include "tools"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if (nums.empty()) return -1;
        // if (nums.size() == 1) return nums[0];
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];
        
        int cnt = 0;
        int candidate;
        for (int num : nums) {
            if (cnt == 0) candidate = num;
            cnt += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};