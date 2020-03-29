#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    bool isLegal(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited,int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        isVisited[i][j] = true;
        int cnt = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            cnt++;
            if (isLegal(x - 1, y) && !isVisited[x - 1][y] && grid[x - 1][y]) {
                q.push({x - 1, y});
                isVisited[x - 1][y] = true;
            }
            if (isLegal(x + 1, y) && !isVisited[x + 1][y] && grid[x + 1][y]) {
                q.push({x + 1, y});
                isVisited[x + 1][y] = true;
            } 
            if (isLegal(x, y - 1) && !isVisited[x][y - 1] && grid[x][y - 1]) {
                q.push({x, y - 1});
                isVisited[x][y - 1] = true;
            }
            if (isLegal(x, y + 1) && !isVisited[x][y + 1] && grid[x][y + 1]) {
                q.push({x, y + 1});
                isVisited[x][y + 1] = true;
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !isVisited[i][j])
                    maxArea = max(maxArea, bfs(grid, isVisited, i, j));
            }
        }
        return maxArea;
    }
};