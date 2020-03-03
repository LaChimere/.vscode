#include "tools"
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size(), col = M[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = 0;
                for (int now_r = i - 1; now_r <= i + 1; now_r++) {
                    for (int now_c = j - 1; now_c <= j + 1; now_c++) {
                        if (0 <= now_r && now_r < row && 0 <= now_c && now_c < col) {
                            res[i][j] += M[now_r][now_c];
                            cnt++;
                        }
                    }
                }
                res[i][j] /= cnt;
            }
        }
        return res;
        
        // for (int k = 0; k < row * col; k++) {
        //     int r = k / col, c = k % col;
        //     int x1 = c, x2 = c, y1 = r, y2 = r, sum = 0;
        //     if (c - 1 >= 0) x1 = c - 1;
        //     if (c + 1 < col) x2 = c + 1;
        //     if (r - 1 >= 0) y1 = r - 1;
        //     if (r + 1 < row) y2 = r + 1;
        //     for (int i = y1; i <= y2; i++) {
        //         for (int j = x1; j <= x2; j++)
        //             sum += M[i][j];
        //     }
        //     int cnt = (y2 - y1 + 1) * (x2 - x1 + 1);
        //     res[r][c] = sum / cnt;
        // }
        // return res;
    }
};