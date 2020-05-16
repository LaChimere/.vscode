#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        long long b = abs(n);
        
        double ans = 1;
        while (b) {
            if (b & 1) ans *= x;
            x *= x;
            b >>= 1;
        }
        
        return ans;
    }
};