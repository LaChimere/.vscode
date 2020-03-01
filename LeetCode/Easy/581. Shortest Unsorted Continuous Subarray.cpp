#include "tools"
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1]) minVal = min(minVal, nums[i]);
        for (int i = nums.size() - 2; i >= 0; i--)
            if (nums[i] > nums[i + 1]) maxVal = max(maxVal, nums[i]);
        int left, right;
        for (left = 0; left < nums.size(); left++)
            if (minVal < nums[left]) break;
        for (right = nums.size() - 1; right >= 0; right--)
            if (maxVal > nums[right]) break;
        return right > left ? right - left + 1 : 0;
        
        // stack<int> st;
        // int left = nums.size(), right = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     while (!st.empty() && nums[st.top()] > nums[i]) {
        //         left = min(left, st.top());
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // while (!st.empty()) st.pop();
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     while (!st.empty() && nums[st.top()] < nums[i]) {
        //         right = max(right, st.top());
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // return right - left > 0 ? right - left + 1 : 0;
        
        // int left, right;
        // for (left = 0; left < nums.size(); left++) {
        //     int i;
        //     for (i = left + 1; i < nums.size(); i++)
        //         if (nums[i] < nums[left]) break;
        //     if (i != nums.size()) break;
        // }
        // for (right = nums.size() - 1; right > left; right--) {
        //     int i;
        //     for (i = right - 1; i >= left; i--)
        //         if (nums[i] > nums[right]) break;
        //     if (i >= left) break;
        // }
        // return right - left + 1;
    }
};