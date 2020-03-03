#include "tools"
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b) return true;
        }
        return false;
        
        // for (int i = 2; i <= c / i; i++) {
        //     int cnt = 0;
        //     if (c % i == 0) {
        //         while (c % i == 0) {
        //             cnt++;
        //             c /= i;
        //         }
        //         if (i % 4 == 3 && cnt % 2 == 1)
        //             return false;
        //     }
        // }
        // return c % 4 != 3;
    }
};