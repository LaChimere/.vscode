#include "tools"
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = '\0';
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
        
        // int len = s.length(), letters[26] = {0};
        // for (int i = 0; i < len; i++) {
        //     letters[s[i] - 'a']++;
        //     letters[t[i] - 'a']--;
        // }
        // letters[t[len] - 'a']--;
        // for (int i = 0; i < 26; i++) {
        //     if (letters[i] == -1)
        //         return 'a' + i;
        // }
        // return '\0';
    }
};