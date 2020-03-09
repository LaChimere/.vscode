#include "tools"
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) return 0;
        int cnt = 0;
        for (int j = 0; j < A[0].size(); j++)
            for (int i = 0; i < A.size() - 1; i++)
                if (A[i][j] > A[i + 1][j]) {cnt++; break;}
        return cnt;
    }
};