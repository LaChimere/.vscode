#include "tools"
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = INT_MAX, cnt = 0;
        for (int num : nums)
            if (num < minVal) minVal = num;
        for (int num : nums) cnt += num - minVal;
        return cnt;
    }
};