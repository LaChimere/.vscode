#include "tools"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> myset;
        for (int num : nums) myset.insert(num);
        auto it = myset.rbegin();
        if (myset.size() < 3) return *it;
        else {it++, it++;}
        return *it;
    }
};