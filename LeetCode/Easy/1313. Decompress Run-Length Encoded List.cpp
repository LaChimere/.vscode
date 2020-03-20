#include "tools"
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; (i << 1) + 1 < nums.size(); i++) {
            int freq = nums[i << 1], val = nums[(i << 1) + 1];
            res.insert(res.end(), freq, val);
        }
        return res;
    }
};