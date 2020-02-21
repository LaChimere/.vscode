#include "tools"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> set1;
        vector<int> ans;
        for (int num : nums1) set1.insert(num);
        for (int num : nums2) {
            auto it = set1.find(num);
            if (it != set1.end()) {
                ans.push_back(num);
                set1.erase(it);
            }
        }
        return ans;
    }
};