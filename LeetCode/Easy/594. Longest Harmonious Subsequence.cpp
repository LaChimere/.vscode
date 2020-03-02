#include "tools"
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> elem;
        for (int num : nums) elem[num]++;
        int res = 0, sum = 0;
        for (auto it = elem.begin(); it != elem.end(); it++) {
            auto next = it;
            next++;
            if (next == elem.end()) break;
            if (next->first - it->first == 1) {
                sum = next->second + it->second;
                res = max(res, sum);
            }
        }
        return res;
    }
};