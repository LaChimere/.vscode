#include "tools"
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) return false;
        if ((num & (num - 1)) != 0) return false;
        if ((num & 0x55555555) != num) return false;
        return true;
        
        // if (num < 1) return false;
        // while (num % 4 == 0)
        //     num >>= 2;
        // return num == 1;
    }
};