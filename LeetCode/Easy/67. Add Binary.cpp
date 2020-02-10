#include "tools"
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.length(), len_b = b.length();
        int len;
        if (len_a < len_b) {
            len = len_b;
            a.append(len - len_a, '0');
        } else {
            len = len_a;
            b.append(len - len_b, '0');
        }
        int low_in = 0;
        for (int i = 0; i < len; i++) {
            a[i] = a[i] - '0' + b[i] + low_in;
            if (a[i] >= '2') {
                a[i] -= 2;
                low_in = 1;
            } else
                low_in = 0;
        }
        if (low_in == 1)
            a += "1";
        reverse(a.begin(), a.end());
        return a;
    }
};