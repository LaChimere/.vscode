#include "tools"
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            /* 
                a与b的异或运算是无进位的，在每次异或之前计算出应该进行进位的位置，然后进行本次异或操作。
                异或之后令b为本次异或的应进位carry。
                直到b为0，即carry为0，表示不再有进位产生，计算结束，a中即为计算结果。
            */
            auto carry = unsigned(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};