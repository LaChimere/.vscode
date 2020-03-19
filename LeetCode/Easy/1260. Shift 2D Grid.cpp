#include "tools"
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= m * n;
        vector<int> nums(m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                nums[i * n + j] = grid[i][j];
        for (int index = 0; index < m * n; index++) {
            int i = ((index + k) % (m * n)) / n;
            int j = ((index + k) % (m * n)) % n;
            grid[i][j] = nums[index];
        }
        return grid;
    }
};