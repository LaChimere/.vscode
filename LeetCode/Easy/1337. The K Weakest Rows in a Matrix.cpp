#include "tools"
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        map<int, vector<int>> hash;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size() && mat[i][j]; j++) cnt++;
            hash[cnt].push_back(i);
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            for (int i : it->second) {
                res.push_back(i);
                k--;
                if (k == 0) break;
            }
            if (k == 0) break;
        }
        return res;
    }
};