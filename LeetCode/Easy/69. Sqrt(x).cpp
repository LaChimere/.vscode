#include "tools"
class Solution {
public:
    int mySqrt(int x) {
        // 牛顿迭代法
        // if (x < 2) return x;
        // double x1 = x;
        // double x2 = (x1 + x / x1) / 2.0;
        // while (fabs(x2 - x1) >= 0.5) {
        //     x1 = x2;
        //     x2 = (x1 + x / x1) / 2.0;
        // }
        // return int(x2);

        // 二分查找法
        long long low = 0, high = x / 2 + 1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * mid == x) return mid;
            else if (mid * mid < x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};