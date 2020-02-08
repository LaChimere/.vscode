#include "ignored"
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        else return haystack.find(needle);
    }
};