#include "tools"
class Solution {
private:
    void nextGreaterElement(vector<int> nums, unordered_map<int, int>& hash) {
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) st.pop();
            hash[nums[i]] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        nextGreaterElement(nums2, hash);
        for (int i = 0; i < nums1.size(); i++) {
            if (hash.find(nums1[i]) == hash.end()) nums1[i] = -1;
            else nums1[i] = hash[nums1[i]];
        }
        return nums1;
        
        // unordered_map<int, int> hash;
        // for (int i = 0; i < nums2.size(); i++) {
        //     int j;
        //     for (j = i + 1; j < nums2.size(); j++)
        //         if (nums2[j] > nums2[i]) {
        //             hash[nums2[i]] = nums2[j];
        //             break;
        //         }
        //     if (j == nums2.size()) hash[nums2[i]] = -1;
        // }
        // for (int i = 0; i < nums1.size(); i++) {
        //     if (hash.find(nums1[i]) == hash.end())
        //         nums1[i] = -1;
        //     else nums1[i] = hash[nums1[i]];
        // }
        // return nums1;
    }
};