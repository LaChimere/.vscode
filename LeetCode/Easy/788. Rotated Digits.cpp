#include "tools"
class Solution {
private:
    bool rotateNum(int num) {
        bool changed = false;
        while (num) {
            int digit = num % 10;
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                changed = true;
            num /= 10;
        }
        return changed;
    }
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int n = 1; n <= N; n++)
            if (rotateNum(n)) cnt++;
        return cnt;
    }
};