#include "tools"
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int tail = 0;
        vector<bool> ans;
        for (int bit : A) {
            tail = (tail << 1) + bit;
            if (tail > 9) tail -= 10;
            if (tail == 0 || tail == 5) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};