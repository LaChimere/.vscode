#include "tools"
class Solution {
public:
    int findComplement(int num) {
        unsigned b = 1;
        while (b <= num) b <<= 1;
        return b - 1 - num;
    }
};