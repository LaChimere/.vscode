#include "tools"
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        int i = 0, j = 0;
        while (j < len) {
            if (arr[i] == 0) ++j;
            ++i, ++j;
        }
        --i, --j;
        while (i >= 0) {
            if (j < len) arr[j] = arr[i];
            if (arr[i] == 0) arr[--j] = arr[i];
            --i, --j;
        }
        
        // for (auto it = arr.begin(); it < arr.end(); it++)
        //     if (*it == 0) {
        //         arr.pop_back();
        //         arr.insert(it, 0);
        //         it++;
        //     }
    }
};