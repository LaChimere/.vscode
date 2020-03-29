#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int INF = 9999;
    bool isLegal(const int& x, const int& y, const int& n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INF));
                    
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dis[i][j] = 0;
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (!isLegal(x, y, n)) continue;
                    dis[i][j] = min(dis[i][j], dis[x][y] + 1);
                }
            }
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (!isLegal(x, y, n)) continue;
                    dis[i][j] = min(dis[i][j], dis[x][y] + 1);
                }
            }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dis[i][j]);
        return (ans == 0 || ans == INF) ? -1 : ans;
    }
};