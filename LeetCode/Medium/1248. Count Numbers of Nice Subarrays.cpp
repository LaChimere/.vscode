#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd;
        odd.push_back(0);
        for (int num : nums)
            odd.push_back(odd.back() + (num & 1));
        
        unordered_map<int, int> hash;
        int cnt = 0;
        for (int i : odd) {
            cnt += hash[i - k];
            hash[i]++;
        }
        return cnt;
    }
};