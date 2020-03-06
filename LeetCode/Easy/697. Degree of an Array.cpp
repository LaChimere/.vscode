#include "tools"
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        int degree = INT_MAX, times = 0;
        for (int i = 0; i < nums.size(); i++) hash[nums[i]].push_back(i);
        for (auto it = hash.begin(); it != hash.end(); it++) {
            int len = it->second.size();
            if (len > times) {
                times = len;
                degree = it->second[len - 1] - it->second[0] + 1;
            } else if (len == times)
                degree = min(degree, it->second[len - 1] - it->second[0] + 1);
        }
        return degree;
    }
};