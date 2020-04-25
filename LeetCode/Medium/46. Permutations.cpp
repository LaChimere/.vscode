#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<int> chosen;
    vector<int> ans;
    void getPermutation(const vector<int>& nums, vector<vector<int>>& res) {
        if (ans.size() == nums.size()) {
            res.emplace_back(ans);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (chosen.find(nums[i]) != chosen.end())
                continue;
            ans.push_back(nums[i]);
            chosen.insert(nums[i]);
            getPermutation(nums, res);
            chosen.erase(nums[i]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getPermutation(nums, res);
        return res;
    }
};