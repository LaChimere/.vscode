#include "tools"
class Solution {
public:
    string sortString(string s) {
        int letters[26] = {0};
        for (char c : s) letters[c - 'a']++;
        string res;
        int cnt = 0, len = s.length();
        while (cnt < len) {
            for (int i = 0; i < 26 && cnt < len; i++)
                if (letters[i]) {
                    res.push_back('a' + i);
                    letters[i]--;
                    cnt++;
                }
            for (int i = 25; i >= 0 && cnt < len; i--)
                if (letters[i]) {
                    res.push_back('a' + i);
                    letters[i]--;
                    cnt++;
                }
        }
        return res;
    }
};