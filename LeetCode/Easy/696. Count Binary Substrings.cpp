#include "tools"
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        long k = (target + 1) / 2L;
        while (k >= 2) {
            double a = ((double)target - k * (k - 1) / 2) / k;
            if ((int)a == a && (int)a > 0) {
                vector<int> res(k);
                for (int i = 0; i < k; i++) res[i] = (int)a + i;
                ans.push_back(res);
            }
            k--;
        }
        return ans;
    }
};