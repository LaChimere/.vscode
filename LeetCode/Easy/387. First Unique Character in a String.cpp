#include "tools"
class Solution {
public:
    int firstUniqChar(string s) {
        int letters[26] = {0};
        for (char c : s) letters[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (letters[s[i] - 'a'] == 1) return i;
        return -1;
    }
};