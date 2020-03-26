#include "tools"
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) return true;
        int len = A.length(), k = 0;
        if (len != B.length()) return false;
        while (k < len) {
            A.push_back(A.front());
            A.erase(A.begin());
            if (A == B) return true;
            k++;
        }
        return false;
    }
};