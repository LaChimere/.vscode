#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, curMin = 1, curMax = 1;
        for (int num : nums) {
            if (num < 0)
                swap(curMin, curMax);
            
            curMax = max(curMax * num, num);
            curMin = min(curMin * num, num);
            
            res = max(res, curMax);
        }
        
        return res;
    }
};