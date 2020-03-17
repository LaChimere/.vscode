#include "tools"
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        vector<int> res;
        int carry = 0, i = 0;
        while (K && i < A.size()) {
            int a = A[i++] + carry + K % 10;
            K /= 10;
            res.emplace_back(move(a % 10));
            carry = a / 10;
        }
        while (i < A.size()) {
            int a = A[i++] + carry;
            res.emplace_back(move(a % 10));
            carry = a / 10;
        }
        while (K) {
            int a = carry + K % 10;
            K /= 10;
            res.emplace_back(move(a % 10));
            carry = a / 10;
        }
        if (carry) res.emplace_back(move(carry));
        reverse(res.begin(), res.end());
        return res;
    }
};