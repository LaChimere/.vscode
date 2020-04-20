#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int m, n;
    
    bool isLegal(const int x, const int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (!isLegal(x, y) || grid[x][y] != '1') return;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
            dfs(grid, x + dx[i], y + dy[i]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
        return cnt;
    }
};