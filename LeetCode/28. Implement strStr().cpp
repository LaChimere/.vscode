#include "ignored"
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        else if (haystack.find(needle) != string::npos)
            return haystack.find(needle);
        else return -1;
    }
};