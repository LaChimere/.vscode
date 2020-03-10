#include "tools"
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2) {
                while (A[j] % 2) j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
        
        // vector<int> odds, evens, indices;
        // for (int i = 0; i < A.size(); i++) {
        //     if (i % 2 == A[i] % 2) continue;
        //     indices.push_back(i);
        //     if (i % 2 == 1) evens.push_back(A[i]);
        //     else odds.push_back(A[i]);
        // }
        // for (int i : indices) {
        //     if (i % 2 == 1) {
        //         A[i] = odds.back();
        //         odds.pop_back();
        //     } else {
        //         A[i] = evens.back();
        //         evens.pop_back();
        //     }
        // }
        // return A;
    }
};