#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) 
                    dist[i][j] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j - 1 >= 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j + 1 < n)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};