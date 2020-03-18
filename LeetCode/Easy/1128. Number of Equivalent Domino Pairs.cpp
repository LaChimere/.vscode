#include "tools"
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> hash;
        int temp, cnt = 0;
        for (auto d : dominoes) {
            temp = d[0] > d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            cnt += hash[temp];
            hash[temp]++;
        }
        return cnt;
    }
};