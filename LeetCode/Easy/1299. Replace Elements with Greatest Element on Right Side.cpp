#include "tools"
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int rightMax = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = temp > rightMax ? temp : rightMax;
        }
        return arr;
        
        // int len = arr.size();
        // vector<int> dp(len, -1);
        // for (int i = len - 2; i >= 0; i--)
        //     dp[i] = max(arr[i + 1], dp[i + 1]);
        // return dp;
    }
};