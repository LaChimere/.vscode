#include "tools"
class Solution {
private:
    bool check(vector<vector<bool>>& g, int N, int k) {
        for (int i = 1; i <= N; i++) {
            if (i == k) continue;
            if (!g[i][k]) return false;
        }
        return true;
    }
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<bool>> g(N + 1, vector<bool>(N + 1, false));
        vector<bool> candidates(N + 1, true);
        for (int i = 0; i < trust.size(); i++) {
            g[trust[i][0]][trust[i][1]] = true;
            candidates[trust[i][0]] = false;
        }
        for (int i = 1; i <= N; i++)
            if (candidates[i] && check(g, N, i)) return i;
        return -1;

        
        // vector<int> degrees(N + 1, 0);
        // for (vector<int> t : trust) {
        //     degrees[t[0]]--;
        //     degrees[t[1]]++;
        // }
        // for (int i = 1; i <= N; i++)
        //     if (degrees[i] == N - 1) return i;
        // return -1;
    }
};