#include "tools"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 位运算
        int bits = 0, mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) bits++;
            mask <<= 1;
        }
        return bits;

        // bitset<32> n_bit(n);
        // string s = n_bit.to_string();
        // int cnt = 0;
        // for (int i = 0; i < s.length(); i++)
        //     if (s[i] == '1') cnt++;
        // return cnt;
    }
};