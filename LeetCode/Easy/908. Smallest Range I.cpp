#include "tools"
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxA = -1, minA = 10001;
        for (int a : A) {
            maxA = max(maxA, a);
            minA = min(minA, a);
        }
        return max(maxA - minA - 2 * K, 0);
    }
};