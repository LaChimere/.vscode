#include "tools"
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n != 0) {
            int c = n % 26;
            if (c == 0) {c = 26; n -= 1;}
            res.insert(res.begin(), 'A' + c - 1);
            n /= 26;
        }
        return res;
    }
};