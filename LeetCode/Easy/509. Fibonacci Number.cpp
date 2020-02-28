#include "tools"
class Solution {
public:
    int fib(int N) {
        int ans[31];
        ans[0] = 0, ans[1] = 1;
        for (int i = 2; i < 31; i++)
            ans[i] = ans[i - 1] + ans[i - 2];
        return ans[N];
    }
};