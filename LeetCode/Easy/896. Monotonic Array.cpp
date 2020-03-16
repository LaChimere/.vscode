#include "tools"
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if (len < 3) return true;
        bool flag1 = false, flag2 = false;
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i - 1]) flag1 = true;
            else if (A[i] < A[i - 1]) flag2 = true;
            if (flag1 && flag2) return false;
        }
        return true;
        
        // int len = A.size();
        // if (len < 3) return true;
        // int i = 1;
        // while (i < len && A[i] >= A[i - 1]) i++;
        // if (i == len) return true;
        // i = 1;
        // while (i < len && A[i] <= A[i - 1]) i++;
        // return i == len;
    }
};