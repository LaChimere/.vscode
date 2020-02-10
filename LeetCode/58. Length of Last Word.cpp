#include "tools"
class Solution {
public:
    int lengthOfLastWord(string s) {
        int low, high = s.length() - 1;
        while (high >= 0) {
            if (s[high] == ' ') high--;
            else break;
        }
        low = high;
        while (low >= 0) {
            if (s[low] != ' ') low--;
            else break;
        }
        return high - low;
    }
};