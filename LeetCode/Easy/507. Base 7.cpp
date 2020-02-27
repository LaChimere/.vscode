#include "tools"
class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0) return "-" + convertToBase7(-num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
        
        // if (num == 0) return "0";
        // string res;
        // int flag = 0;
        // if (num < 0) {flag = 1; num = -num;}
        // while (num != 0) {
        //     res = to_string(num % 7) + res;
        //     num /= 7;
        // }
        // if (flag == 1) res = "-" + res;
        // return res;
    }
};