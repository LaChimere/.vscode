#include "tools"
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size(), col = M[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        for (int i = 0; i < row * col; i++) {
            int r = i / col, c = i % col;
            int x1 = c, x2 = c, y1 = r, y2 = r, sum = 0;
            if (c - 1 >= 0) x1 = c - 1;
            if (c + 1 < col) x2 = c + 1;
            if (r - 1 >= 0) y1 = r - 1;
            if (r + 1 < row) y2 = r + 1;
            for (int j = y1; j <= y2; j++) {
                for (int k = x1; k <= x2; k++)
                    sum += M[j][k];
            }
            int cnt = (y2 - y1 + 1) * (x2 - x1 + 1);
            res[r][c] = sum / cnt;
        }
        return res;
    }
};