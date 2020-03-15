#include "tools"
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int anchor = -1, cur, len = seats.size(), maxDis = INT_MAX;
        for (cur = 0; cur < len; cur++) {
            if (seats[cur] == 1) anchor = cur;
            else if (cur == 0) seats[cur] = INT_MIN;
            else seats[cur] = anchor - cur;
        }
        anchor = len;
        for (cur = len - 1; cur >= 0; cur--) {
            if (seats[cur] == 1) anchor = cur;
            else if (cur == len - 1) maxDis = min(seats[cur], maxDis);
            else maxDis = min(max(cur - anchor, seats[cur]), maxDis);
        }
        return -maxDis;
    }
};