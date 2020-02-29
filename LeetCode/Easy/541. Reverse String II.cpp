#include "tools"
class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() <= k) {reverse(s.begin(), s.end()); return s;}
        reverse(s.begin(), s.begin() + k);
        if (s.length() <= k << 1) return s;
        return s.substr(0, k << 1) + reverseStr(s.substr(k << 1), k);
    }
};