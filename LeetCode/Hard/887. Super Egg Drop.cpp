#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;
    
    int dp(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        if (memo.find(k * 10000 + n) != memo.end()) return memo[k * 10000 + n];
        int res = INT_MAX, left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int broken = dp(k - 1, mid - 1);
            int unbroken = dp(k, n - mid);
            if (broken > unbroken) {
                right = mid - 1;
                res = min(res, broken + 1);
            } else {
                left = mid + 1;
                res = min(res, unbroken + 1);
            }
        }
        memo[k * 10000 + n] = res;
        return res;
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};