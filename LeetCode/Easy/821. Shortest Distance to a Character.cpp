#include "tools"
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int anchor = 0, cur, len = S.length();
        vector<int> res(len, INT_MAX);
        for (cur = 0; cur < len; cur++) {
            if (S[cur] != C) continue;
            res[cur] = 0;
            for (int k = 1; cur - k >= anchor; k++)
                res[cur - k] = k;
            anchor = cur + 1;
        }
        anchor = len - 1;
        for (cur = len - 1; cur >= 0; cur--) {
            if (S[cur] != C) continue;
            for (int k = 1; cur + k <= anchor; k++)
                res[cur + k] = min(res[cur + k], k);
            anchor = cur - 1;
        }
        return res;
    }
};