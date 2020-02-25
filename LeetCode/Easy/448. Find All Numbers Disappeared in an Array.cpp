#include "tools"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - 1) % nums.size();
            nums[index] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= nums.size())
                res.push_back(i + 1);
        return res;
        
        // vector<int> res;
        // vector<int> times(nums.size() + 1, 0);
        // for (int i = 0; i < nums.size(); i++)
        //     times[nums[i]]++;
        // for (int i = 1; i < times.size(); i++)
        //     if (times[i] == 0)
        //         res.push_back(i);
        // return res;
    }
};