#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0, maxPos = 0, steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end) {
                end = maxPos;
                steps++;
            }
        }
        return steps;
    }
};