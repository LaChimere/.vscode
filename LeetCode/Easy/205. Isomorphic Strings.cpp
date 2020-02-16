#include "tools"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        int len = s.length();
        unordered_map<char, char> hash;
        unordered_map<char, bool> isMapped;
        for (int i = 0; i < len; i++) {
            if (hash.find(s[i]) != hash.end()) {
                if (hash[s[i]] != t[i])
                    return false;
            } else {
                if (isMapped.find(t[i]) != isMapped.end()) return false;
                hash[s[i]] = t[i];
                isMapped[t[i]] = true;
            }
        }
        return true;
    }
};