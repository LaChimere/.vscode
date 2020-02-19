#include "tools"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZero = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0)
                swap(nums[lastNonZero++], nums[cur]);
        }
        
        // int cntZero = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0) cntZero++;
        //     else nums[i - cntZero] = nums[i];
        // }
        // for (int i = nums.size() - cntZero; i < nums.size(); i++)
        //     nums[i] = 0;
    }
};