#include "tools"
class Solution {
private:
    const int MAXLEN = 100;
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        if (S.empty()) return {0, 0};
        int line = 0, lastWidth = 0;
        for (char c : S) {
            if (lastWidth + widths[c - 'a'] <= MAXLEN)
                lastWidth += widths[c - 'a'];
            else {
                line++;
                lastWidth = widths[c - 'a'];
            }
        }
        return {line + 1, lastWidth};
    }
};