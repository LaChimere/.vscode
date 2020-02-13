#include "tools"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using Hash Table, time complexity: O(n), space complexity: O(n)
        // unordered_set<int> hash;
        // int result;
        // for (auto i : nums) {
        //     if (hash.count(i)) hash.erase(i);
        //     else hash.insert(i);
        // }
        // for (auto j : hash) result = j;
        // return result;

        // exclusive OR, time complexity: O(n), space comlexity: O(1)
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};