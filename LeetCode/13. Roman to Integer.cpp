#include "ignored"
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNum;
        romanNum.insert(make_pair('I', 1));
        romanNum.insert(make_pair('V', 5));
        romanNum.insert(make_pair('X', 10));
        romanNum.insert(make_pair('L', 50));
        romanNum.insert(make_pair('C', 100));
        romanNum.insert(make_pair('D', 500));
        romanNum.insert(make_pair('M', 1000));
        int ans = 0;
        for (int i = 0; i < s.length();) {
            if (romanNum[s[i]] >= romanNum[s[i+1]]) {
                ans += romanNum[s[i]];
                i++;
            } else {
                ans = ans + (romanNum[s[i+1]] - romanNum[s[i]]);
                i += 2;
            }
        }
        return ans;
    }
};