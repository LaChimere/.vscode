#include "tools"
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        int j = 0;
        while (j < len && A[j] < 0) j++;
        int i = j - 1, k = 0;
        vector<int> res(len);
        while (i >= 0 && j < len) {
            int a = A[i] * A[i], b = A[j] * A[j];
            if (a < b) {
                res[k++] = a;
                i--;
            } else {
                res[k++] = b;
                j++;
            }
        }
        while (i >= 0) res[k++] = A[i] * A[i--];
        while (j < len) res[k++] = A[j] * A[j++];
        return res;
        
        
        // for (int i = 0; i < A.size(); i++) A[i] *= A[i];
        // sort(A.begin(), A.end());
        // return A;
    }
};