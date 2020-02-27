#include "tools"
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        for (auto it = S.begin(); it != S.end();) {
            if (*it == '-') S.erase(it);
            else it++;
        }
        int cnt = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            cnt = (cnt + 1) % K;
            S[i] = toupper(S[i]);
            if (cnt == 0 && i != 0) S.insert(i, "-");
        }
        return S;
    }
};