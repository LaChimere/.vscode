#include "tools"
class Solution {
private:
    bool rot(vector<vector<int>>& grid, int& freshNum) {
        int preFreshNum = freshNum;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int i = cur.first, j = cur.second;
            q.pop();
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {grid[i - 1][j] = 2; freshNum--;}
            if (i + 1 < grid.size() && grid[i + 1][j] == 1) {grid[i + 1][j] = 2; freshNum--;}
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {grid[i][j - 1] = 2; freshNum--;}
            if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {grid[i][j + 1] = 2; freshNum--;}
        }
        return preFreshNum != freshNum;
    }
    int existFresh(vector<vector<int>>& grid) {
        int cntFresh = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1) cntFresh++;
        return cntFresh;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshNum = existFresh(grid);
        if (freshNum == 0) return 0;
        int minutes = 0;
        while (rot(grid, freshNum)) minutes++;
        return freshNum > 0 ? -1 : minutes;
    }
};