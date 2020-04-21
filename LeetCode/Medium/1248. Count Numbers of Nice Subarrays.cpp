#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 利用前缀和的思想, 求出 nums 中奇数个数的前缀和
        vector<int> odd;
        odd.push_back(0);
        for (int num : nums)
            odd.push_back(odd.back() + (num & 1));
        
        //利用 Two Sum 的思想, 找出 odd 中满足 odd[j] - odd[i] == k 的对数
        unordered_map<int, int> hash;
        int cnt = 0;
        for (int i : odd) {
            cnt += hash[i - k];
            hash[i]++;
        }
        return cnt;
    }
};