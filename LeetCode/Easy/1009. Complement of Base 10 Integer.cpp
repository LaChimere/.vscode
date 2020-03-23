#include "tools"
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        vector<int> res;
        while (N) {
            if (N & 1) res.emplace_back(1);
            else res.emplace_back(0);
            N >>= 1;
        }
        int ans = 0;
        for (int i = res.size() - 1; i >= 0; i--)
            ans = (ans << 1) + (res[i] ^ 1);
        return ans;
    }
};