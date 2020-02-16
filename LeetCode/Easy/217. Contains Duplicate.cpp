#include "tools"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> elements;
        for (int i = 0; i < nums.size(); i++) {
            if (elements.count(nums[i]) != 0)
                return true;
            else elements.insert(nums[i]);
        }
        return false;
    }
};