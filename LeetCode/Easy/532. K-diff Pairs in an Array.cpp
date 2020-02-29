#include "tools"
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, left = 0, right = 0;
        while (right < nums.size()) {
            while (left == right || (right < nums.size() && nums[right] - nums[left] < k))
                right++;
            int found = 0;
            while (right < nums.size() && nums[right] - nums[left] == k) {
                found = 1;
                right++;
            }
            cnt += found;
            while (right < nums.size() && left < right && nums[right] - nums[left] > k)
                left++;
        }
        return cnt;
    }
};