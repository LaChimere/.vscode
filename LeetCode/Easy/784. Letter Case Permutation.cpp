#include "tools"
class Solution {
private:
    void permuteString(vector<string>& str, string s, int start, int len) {
        if (start >= len) {str.push_back(s); return;}
        int i;
        for (i = start; i < len && !isalpha(s[i]); i++);
        // 不改
        permuteString(str, s, i + 1, len);
        // 改
        if (i < len) {
            s[i] ^= 1 << 5;
            permuteString(str, s, i + 1, len);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> str;
        permuteString(str, S, 0, S.length());
        return str;
    }
};