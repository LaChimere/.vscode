#include "tools"
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> adj(N);
        for (auto path : paths) {
            adj[path[0] - 1].push_back(path[1] - 1);
            adj[path[1] - 1].push_back(path[0] - 1);
        }
        vector<int> flowers(N, 0);
        for (int i = 0; i < N; i++) {
            unordered_set<int> colors({1, 2, 3, 4});
            for (int j = 0; j < adj[i].size(); j++)
                colors.erase(flowers[adj[i][j]]);
            flowers[i] = *colors.begin();
        }
        return flowers;
    }
};