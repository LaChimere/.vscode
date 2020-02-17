#include "tools"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
        // unordered_map<int, int> powerOfTwo;
        // int i = 0, result = 1;
        // while (i < 31) {
        //     powerOfTwo[result] = i;
        //     result <<= 1;
        //     i++;
        // }
        // if (powerOfTwo.find(n) != powerOfTwo.end())
        //     return true;
        // else return false;
    }
};