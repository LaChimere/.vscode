#include "ignored"
class Solution {
public:
    bool isPalindrome(int x) {
        bool flag = true;
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        if (s != t)
            flag = false;
        return flag;
    }
};