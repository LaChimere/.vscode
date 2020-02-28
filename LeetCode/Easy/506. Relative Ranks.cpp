#include "tools"
class Solution {
private:
    static bool cmp(int a, int b) {return a > b;}
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) hash[nums[i]] = i;
        sort(nums.begin(), nums.end(), cmp);
        if (nums.size() > 0) res[hash[nums[0]]] = "Gold Medal";
        if (nums.size() > 1) res[hash[nums[1]]] = "Silver Medal";
        if (nums.size() > 2) res[hash[nums[2]]] = "Bronze Medal";
        for (int i = 3; i < nums.size(); i++)
            res[hash[nums[i]]] = to_string(i + 1);
        return res;
    }
};