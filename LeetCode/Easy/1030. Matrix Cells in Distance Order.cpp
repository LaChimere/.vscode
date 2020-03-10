#include "tools"
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        multimap<int, vector<int>> matrix;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                int dis = abs(i - r0) + abs(j - c0);
                matrix.insert({dis, {i, j}});
            }
        vector<vector<int>> res;
        for (auto it = matrix.begin(); it != matrix.end(); it++)
            res.push_back(it->second);
        return res;
    }
};