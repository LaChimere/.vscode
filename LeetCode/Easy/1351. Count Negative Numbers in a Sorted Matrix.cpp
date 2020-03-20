#include "tools"
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size(), cnt = 0;
        for (auto v : grid)
            for (int j = n - 1; j >= 0 && v[j] < 0; j--) cnt++;
        return cnt;
    }
};