#include "tools"
class Solution {
private:
    static bool cmp(int a, int b) {return a > b;}
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i + 2 < A.size(); i++) {
            if (A[i + 1] + A[i + 2] > A[i])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};