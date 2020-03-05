#include "tools"
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int len = A.length() * 2 + B.length();
        int cnt = 1;
        for (string s = A; s.length() <= len; s += A, cnt++)
            if (s.length() >= B.length() && s.find(B) != string::npos)
                return cnt;
        return -1;
    }
};