#include "tools"
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int len = grid.size();
        int front = 0, left = 0, up = 0;
        for (int i = 0; i < len; i++) {
            int maxRow = 0;
            for (int j = 0; j < len; j++) {
                if (grid[i][j]) up++;
                maxRow = max(maxRow, grid[i][j]);
            }
            left += maxRow;
        }
        for (int j = 0; j < len; j++) {
            int maxCol = 0;
            for (int i = 0; i < len; i++)
                maxCol = max(maxCol, grid[i][j]);
            front += maxCol;
        }
        return front + left + up;
    }
};