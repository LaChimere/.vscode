#include "tools"
class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26] = {0}, upper[26] = {0};
        for (char c : s) {
            if (islower(c)) lower[c - 'a']++;
            else upper[c - 'A']++;
        }
        int len = 0, single = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] > 1) len += (lower[i] / 2) * 2;
            if (upper[i] > 1) len += (upper[i] / 2) * 2;
            if ((lower[i] % 2) || (upper[i] % 2)) single = 1;
        }
        return len + single;
    }
};