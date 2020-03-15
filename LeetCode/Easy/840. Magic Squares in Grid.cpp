#include "tools"
class Solution {
public:
    int numMagicSquaresInside(const vector<vector<int>>& grid) {
        const unordered_set<int> s{816357492, 834159672, 618753294, 672159834,
                                   492357816, 438951276, 294753618, 276951438};
        const int offset[][2] = {{-2, -2}, {-2, -1}, {-2, 0},
                                 {-1, -2}, {-1, -1}, {-1, 0},
                                 { 0, -2}, { 0, -1}, { 0, 0}};
        int ans = 0;
        for (int i = 2; i < grid.size(); ++i) {
            for (int j = 2; j < grid.size(); ++j) {
                int sum = 0;
                for (int k = 0; k < 9; ++k) {
                    sum *= 10;
                    sum += grid[i + offset[k][0]][j + offset[k][1]];
                }
                ans += s.count(sum);
            }
        }
        return ans;
    }    
};