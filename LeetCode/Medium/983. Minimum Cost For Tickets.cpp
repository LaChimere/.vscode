#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> f(days.back() + 31, 0);
        
        for (int d = days.back(), i = days.size() - 1; d >= days.front(); d--) {
            if (d == days[i]) {
                f[d] = min(f[d + 1] + costs[0], f[d + 7] + costs[1]);
                f[d] = min(f[d], f[d + 30] + costs[2]);
                i--;
            } else
                f[d] = f[d + 1];
        }
        return f[days.front()];
    }
};