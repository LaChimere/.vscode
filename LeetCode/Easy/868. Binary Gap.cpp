#include "tools"
class Solution {
public:
    int binaryGap(int N) {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; i++) {
            if ((N >> i) & 1) {
                if (last >= 0) ans = max(ans, i - last);
                last = i;
            }
        }
        return ans;
        
        // bitset<32> num = bitset<32>(N);
        // if (num.count() < 2) return 0;
        // int anchor, check = 0, gap = 0;
        // while (check < 32) {
        //     int dis = 0;
        //     for (anchor = check; anchor < 32; anchor++)
        //         if (num[anchor] == 1) break;
        //     for (check = anchor + 1; check < 32; check++) {
        //         dis++;
        //         if (num[check] == 1) break;
        //     }
        //     if (check < 32) gap = max(gap, dis);
        // }
        // return gap;
    }
};