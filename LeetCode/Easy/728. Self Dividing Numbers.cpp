#include "tools"
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int num = left; num <= right; num++) {
            int digit = num;
            while (digit) {
                if (digit % 10 == 0 || num % (digit % 10)) break;
                digit /= 10;
            }
            if (digit == 0) res.push_back(num);
        }
        return res;
        
        // vector<int> res;
        // for (int num = left; num <= right; num++) {
        //     bool flag = true;
        //     for (char c : to_string(num)) {
        //         if (c == '0' || num % (c - '0')) {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag) res.push_back(num);
        // }
        // return res;
    }
};