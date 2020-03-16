#include "tools"
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int aSum = 0, bSum = 0;
        for (int n : A) aSum += n;
        for (int n : B) bSum += n;
        int i = 0, j = 0, diff = aSum - bSum;
        vector<int> ans;
        while (i < A.size() && j < B.size()) {
            int aRestSum = aSum - A[i], bRestSum = bSum - B[j];
            int check = 2 * (aRestSum - bRestSum);
            if (check == diff) {
                ans = {A[i], B[j]};
                break;
            } else if (check > diff) {
                i++;
            } else j++;
        }
        return ans;
    }
};