#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<int> chosen;
    vector<int> ans;
    void getPermutation(const vector<int>& nums, vector<vector<int>>& res, int i) {
        if (ans.size() == nums.size()) {
            res.emplace_back(ans);
            return;
        }
        
        for (int k = 0; k < nums.size(); k++) {
            if (chosen.find(nums[k]) != chosen.end())
                continue;
            ans.push_back(nums[k]);
            chosen.insert(nums[k]);
            getPermutation(nums, res, k + 1);
            chosen.erase(nums[k]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getPermutation(nums, res, 0);
        return res;
    }
};