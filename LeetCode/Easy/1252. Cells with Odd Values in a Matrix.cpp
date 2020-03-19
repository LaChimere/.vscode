#include "tools"
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (auto index : indices) {
            int ri = index[0], ci = index[1];
            for (int j = 0; j < m; j++) matrix[ri][j]++;
            for (int i = 0; i < n; i++) matrix[i][ci]++;
        }
        int odd = 0;
        for (auto row : matrix)
            for (int elem : row)
                if (elem & 1) odd++;
        return odd;
    }
};