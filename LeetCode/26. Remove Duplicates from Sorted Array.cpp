#include "ignored"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() != 0) {
            int nowCheck = *nums.begin();
            auto it = nums.begin() + 1;
            while (it != nums.end()) {
                if (*it == nowCheck) nums.erase(it);
                else nowCheck = *it++;
            }
        }
        return nums.size();
    }
};