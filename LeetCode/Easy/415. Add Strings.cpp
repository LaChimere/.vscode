#include "tools"
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int carry = 0, now = 0, i = 0;
        while (i < num1.length()) {
            if (i < num2.length())
                now = num1[i] + num2[i] - 2 * '0' + carry;
            else now = num1[i] - '0' + carry;
            if (now > 9) {
                carry = 1;
                ans = to_string(now - 10) + ans;
            } else {
                carry = 0;
                ans = to_string(now) + ans;
            }
            i++;
        }
        return carry == 1 ? "1" + ans : ans;
    }
};