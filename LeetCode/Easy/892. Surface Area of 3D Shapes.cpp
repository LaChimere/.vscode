#include "tools"
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0, N = grid.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) sum += 6 + 4 * (grid[i][j] - 1);
                if (i - 1 >= 0) sum -= min(grid[i - 1][j], grid[i][j]);
                if (i + 1 < N) sum -= min(grid[i + 1][j], grid[i][j]);
                if (j - 1 >= 0) sum -= min(grid[i][j - 1], grid[i][j]);
                if (j + 1 < N) sum -= min(grid[i][j + 1], grid[i][j]);
            }
        }
        return sum;
    }
};