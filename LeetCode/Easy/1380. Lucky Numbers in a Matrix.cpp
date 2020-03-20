#include "tools"
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> luckyNums;
        for (int i = 0; i < m; i++) {
            int rowMin = INT_MAX, j, k, minJ;
            for (j = 0; j < n; j++) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    minJ = j;
                }
            }
            for (k = 0; k < m; k++)
                if (matrix[k][minJ] > rowMin) break;
            if (k == m) luckyNums.push_back(rowMin);
        }
        return luckyNums;
    }
};