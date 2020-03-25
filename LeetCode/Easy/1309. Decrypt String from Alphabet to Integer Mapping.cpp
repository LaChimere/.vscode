#include "tools"
class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '#') {
                res = char(s[i] - '0' - 1 + 'a') + res;
            } else {
                int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                res = char('a' + num - 1) + res;
                i -= 2;
            }
        }
        return res;
    }
};