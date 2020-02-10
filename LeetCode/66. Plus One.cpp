#include "tools"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i] += 1;
        while (i > 0) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[--i] += 1;
            } else
                return digits;
        }
        if (digits[0] == 10) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};