#include "tools"
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(105, 0), res(nums.size());
        for (int num : nums) cnt[num + 1]++;
        for (int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < nums.size(); i++) res[i] = cnt[nums[i]];
        return res;
    }
};