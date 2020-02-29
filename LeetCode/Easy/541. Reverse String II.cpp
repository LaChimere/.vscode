#include "tools"
class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() <= k) {reverse(s.begin(), s.end()); return s;}
        reverse(s.begin(), s.begin() + k);
        if (s.length() <= 2 * k) return s;
        return s.substr(0, 2 * k) + reverseStr(s.substr(2 * k), k);
    }
};