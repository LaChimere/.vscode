#include "tools"
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int threshold = arr.size() >> 2;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i + threshold] == arr[i]) return arr[i];
        return -1;
    }
};