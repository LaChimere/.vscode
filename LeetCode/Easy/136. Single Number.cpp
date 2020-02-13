#include "tools"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using Hash Table, time complexity: O(n), space complexity: O(n)
        // unordered_map<int, int> hash;
        // int result = nums[0];
        // hash[nums[0]] = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     if (hash.find(nums[i]) != hash.end())
        //         hash[nums[i]]++;
        //     else hash[nums[i]] = 1;
        // }
        // for (auto it = hash.begin(); it != hash.end(); it++)
        //     if (it->second == 1) result = it->first;
        // return result;
        
        // exclusive OR, time complexity: O(n), space comlexity: O(1)
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};