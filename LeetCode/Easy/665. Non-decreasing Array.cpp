#include "tools"
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3) return true;
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                cnt++;
                if (cnt > 1) return false;
                if (i > 0 && nums[i - 1] > nums[i + 1])
                    nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};