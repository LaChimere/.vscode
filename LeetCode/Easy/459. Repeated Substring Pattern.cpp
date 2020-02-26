#include "tools"
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // for (size_t len = 1; len <= s.length() / 2; len++) {
        //     if (s.length() % len != 0) continue;
        //     size_t i = len;
        //     for (; i < s.length() && s[i % len] == s[i]; i++);
        //     if (i == s.length()) return true;
        // }
        // return false;

        // return (s + s).find(s, 1) != s.size();
        
        for (size_t len = 1; len <= s.length() / 2; len++) {
            if (s.length() % len != 0) continue;
            string pattern = s.substr(0, len);
            size_t i = 1;
            for (; i * len < s.length(); i++) {
                string nowCheck = s.substr(i * len, len);
                if (pattern != nowCheck) break;
            }
            if (i * len >= s.length()) return true;
        }
        return false;
    }
};