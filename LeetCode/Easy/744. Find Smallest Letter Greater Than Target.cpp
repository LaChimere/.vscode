#include "tools"
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = char('z' + 1);
        for (char c : letters)
            if (c > target && c < res) res = c;
        if (res != char('z' + 1)) return res;
        target = target - 26;
        for (char c : letters)
            if (c > target && c < res) res = c;
        return res;
    }
};