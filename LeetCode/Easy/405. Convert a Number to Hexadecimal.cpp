#include "tools"
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef", res;
        while (num != 0 && res.length() < 8) {
            res = hex[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};