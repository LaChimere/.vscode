#include "ignored"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()){
                ret.push_back(i);
                ret.push_back(hash[complement]);
                break;
            } else
                hash[nums[i]] = i;
        }
        return ret;
    }
};