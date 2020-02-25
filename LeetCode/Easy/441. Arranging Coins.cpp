#include "tools"
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8 * (double)n)) / 2;
    }
};