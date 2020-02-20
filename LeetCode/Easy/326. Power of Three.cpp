#include "tools"
class Solution {
public:
    bool isPowerOfThree(int n) {
        // pow(3, 19) == 1162261467, pow(3, 20) > INT_MAX
        return (n > 0 && (1162261467 % n == 0));

        // if (n < 1) return false;
        // while (n % 3 == 0)
        //     n /= 3;
        // return n == 1;
    }
};