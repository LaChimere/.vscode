#include "tools"
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cnt1 = 0, cnt2 = 0;
        int i = 0, j = seats.size() - 1;
        while (seats[i] == 0) {cnt1++; i++;}
        while (seats[j] == 0) {cnt2++; j--;}
        int cnt_mid = 0, cnt_max = 0;
        for (int k = i + 1; k <= j; k++) {
            if (seats[k] == 0) cnt_mid++;
            else {
                cnt_max = max(cnt_mid, cnt_max);
                cnt_mid = 0;
            }
        }
        return max(max(cnt1, cnt2), (cnt_max + 1) / 2);

        // int anchor = -1, cur, len = seats.size(), maxDis = INT_MAX;
        // for (cur = 0; cur < len; cur++) {
        //     if (seats[cur] == 1) anchor = cur;
        //     else if (cur == 0) seats[cur] = INT_MIN;
        //     else seats[cur] = anchor - cur;
        // }
        // anchor = len;
        // for (cur = len - 1; cur >= 0; cur--) {
        //     if (seats[cur] == 1) anchor = cur;
        //     else if (cur == len - 1) maxDis = min(seats[cur], maxDis);
        //     else maxDis = min(max(cur - anchor, seats[cur]), maxDis);
        // }
        // return -maxDis;
    }
};