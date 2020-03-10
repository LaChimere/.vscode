#include "tools"
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for (int pos : chips) {
            if (pos % 2) odd++;
            else even++;
        }
        return odd < even ? odd : even;
    }
};