#include "tools"
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        int sum = 0;
        for (int n : A)
            if (n % 2 == 0) sum += n;
        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0], index = queries[i][1];
            int curAi = A[index] + val;
            if (curAi % 2 == 0) {
                sum += val;
                if (A[index] % 2 != 0) sum += A[index];
            } else if (A[index] % 2 == 0) sum -= A[index];
            ans[i] = sum;
            A[index] = curAi;
        }
        return ans;
    }
};