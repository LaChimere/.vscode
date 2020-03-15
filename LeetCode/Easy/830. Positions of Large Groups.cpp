#include "tools"
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int anchor = 0, cur = 0;
        vector<vector<int>> res;
        while (cur < S.length()) {
            if (S[cur] == S[anchor]) cur++;
            else {
                if (cur - anchor >= 3)
                    res.push_back({anchor, cur - 1});
                anchor = cur;
            }
        }
        if (cur - anchor >= 3) res.push_back({anchor, cur - 1});
        return res;
    }
};