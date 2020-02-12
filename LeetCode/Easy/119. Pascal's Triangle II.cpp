#include "tools"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        if (rowIndex == 0) return result;
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> cur = {1};
            for (int j = 1; j < i; j++)
                cur.push_back(result[j-1] + result[j]);
            cur.push_back(1);
            result = cur;
        }
        return result;
    }
};