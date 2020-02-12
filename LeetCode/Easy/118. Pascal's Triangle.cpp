#include "tools"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows < 1) return v;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1);
            v.push_back(row);
        }
        v[0][0] = 1;
        for (int i = 1; i < numRows; i++) {
            v[i][0] = v[i][i] = 1;
            for (int j = 1; j < i; j++)
                v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
        return v;
    }
};