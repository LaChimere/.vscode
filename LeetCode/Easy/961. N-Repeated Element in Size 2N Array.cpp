#include "tools"
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> count(10005, 0);
        int N = A.size() >> 1;
        for (int num : A) {
            count[num]++;
            if (count[num] == N) return num;
        }
        return -1;
    }
};