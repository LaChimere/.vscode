#include "tools"
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int a = num;
        for (int i = 2; i <= num / i; i++)
            if (num % i == 0)  a -= i + num / i;
        if (num != 1) a -= 1;
        if (a == 0) return true;
        else return false;
    }
};