#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isLegal(const int& x, const int& y, const int& n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        queue<pair<int, int>> q;
        int n = grid.size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) q.push(make_pair(i, j));
        
        bool water = false;
        pair<int, int> point;
        while (!q.empty()) {
            point = q.front();
            q.pop();
            int x = point.first, y = point.second;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!isLegal(nx, ny, n) || grid[nx][ny] != 0) continue;
                grid[nx][ny] = grid[x][y] + 1;
                water = true;
                q.push(make_pair(nx, ny));
            }
        }
        
        if (point.first == -1 || !water) return -1;
        return grid[point.first][point.second] - 1;
    }
};