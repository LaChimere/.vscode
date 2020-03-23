#include "tools"
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int D = 0, I = 0, k = 1, m = 1;
        for (char c : S) {
            if (c == 'D') D++;
            else I++;
        }
        vector<int> res(N + 1);
        res[0] = D;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'D') res[i + 1] = D - k++;
            else res[i + 1] = D + m++;
        }
        return res;
    }
};