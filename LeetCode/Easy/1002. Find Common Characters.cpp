#include "tools"
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> count(A.size(), vector<int>(26, 0));
        for (int i = 0; i < A.size(); i++)
            for (char c : A[i]) count[i][c - 'a']++;
        vector<string> res;
        for (int j = 0; j < 26; j++) {
            int cnt = INT_MAX;
            for (int i = 0; i < A.size(); i++)
                cnt = min(cnt, count[i][j]);
            for (int k = 0; k < cnt; k++)
                res.emplace_back(move(string(1, 'a' + j)));
        }
        return res;
    }
};