#include "tools"
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};