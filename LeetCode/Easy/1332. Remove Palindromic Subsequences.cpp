#include "tools"
class Solution {
private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++, right--;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        return isPalindrome(s) ? 1 : 2;
    }
};