#include "tools"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int k = x ^ y, cnt = 0;
        while (k) {
            if (k & 1) cnt++;
            k >>= 1;
        }
        return cnt;
    }
};