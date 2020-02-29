#include "tools"
class Solution {
public:
    string reverseWords(string s) {
        size_t anchor = 0, cur = 0;
        while (cur < s.length()) {
            while (cur < s.length() && s[cur] != ' ') cur++;
            reverse(s.begin() + anchor, s.begin() + cur);
            anchor = cur + 1;
            cur = anchor + 1;
        }
        return s;
    }
};