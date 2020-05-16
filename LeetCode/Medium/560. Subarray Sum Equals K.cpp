#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        s[0] = 1;
        
        int cnt = 0, preSum = 0;
        for (int num : nums)
        {
            preSum += num;
            int complement = preSum - k;
            if (s.find(complement) != s.end())
                cnt += s[complement];
            s[preSum]++;
        }
        
        return cnt;
    }
};