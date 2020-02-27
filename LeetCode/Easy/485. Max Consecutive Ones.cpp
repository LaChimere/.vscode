#include "tools"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) { 
                cnt++;
                maxCnt = cnt > maxCnt ? cnt : maxCnt;
            } else cnt = 0;
        }
        return maxCnt;
    }
};