#include "tools"
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> occur;
        vector<int> count(2005, 0);
        for (int num : arr) count[num + 1000]++;
        for (int cnt : count) {
            if (cnt == 0) continue;
            if (occur.count(cnt)) return false;
            occur.insert(cnt);
        }
        return true;
    }
};