#include "ignored"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()){
                ret.push_back(i);
                ret.push_back(record[complement]);
                break;
            } else
                record[nums[i]] = i;
        }
        return ret;
    }
};