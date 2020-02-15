#include "tools"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 位运算
        int k = 32;
        uint32_t res = 0;
        while (k--) {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;

        // bitset<32> n_bit(n);
        // string s = n_bit.to_string();
        // reverse(s.begin(), s.end());
        // return stol(s, NULL, 2);
    }
};