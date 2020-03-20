#include "tools"
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> count(2005, 0);
        for (int num : arr) count[num + 1000]++;
        for (int i = 500; i <= 1500; i++) {
            if (count[1000] > 1) return true;
            if (i != 1000 && (count[i] && count[2 * i - 1000])) return true;
        }
        return false;
    }
};