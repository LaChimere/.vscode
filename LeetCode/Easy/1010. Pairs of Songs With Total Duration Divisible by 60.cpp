#include "tools"
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(61, 0);
        int len = time.size(), cnt = 0;
        if (len == 0) return 0;
        for (int i = 0; i < len; i++) {
            time[i] %= 60;
            count[time[i]]++;
        }
        sort(time.begin(), time.end());
        for (int t : time) {
            if (t >= 30) break;
            cnt += count[60 - t];
        }
        cnt += (count[0] * (count[0] - 1)) / 2;
        cnt += (count[30] * (count[30] - 1)) / 2;
        return cnt;
    }
};