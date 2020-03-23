#include "tools"
class Solution {
private:
    bool judge(int num) {
        while (num) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            if (judge(i) && judge(n - i))
                return {i, n - i};
        }
        return {};
    }
};