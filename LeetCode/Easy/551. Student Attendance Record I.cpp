#include "tools"
class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        if (s.find("LLL") != string::npos) return false;
        for (char c : s) {
            if (c == 'A') absent++;
            if (absent > 1) return false;
        }
        return true;
    }
};