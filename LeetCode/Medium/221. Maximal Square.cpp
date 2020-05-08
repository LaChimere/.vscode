#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    f[i + 1][j + 1] = min(min(f[i][j + 1], f[i + 1][j]), f[i][j]) + 1;
                    res = max(res, f[i + 1][j + 1]);
                }
            }
        }
        
        return res * res;
    }
};