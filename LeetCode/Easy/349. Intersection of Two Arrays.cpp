#include "tools"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> myset;
        vector<int> intersection;
        for (int num : nums1) myset.insert(num);
        for (int num : nums2) {
            auto it = myset.find(num);
            if (it != myset.end()) {
                intersection.push_back(num);
                myset.erase(num);
            }
        }
        return intersection;
    }
};