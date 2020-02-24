#include "tools"
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && flag) {cnt++; flag = false;}
            else if (s[i] == ' ') flag = true;
        }
        return cnt;
    }
};