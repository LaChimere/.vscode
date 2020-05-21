#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2)
            return s;
        
        int curMax = 1, start = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
            dp[i][i] = true;
        
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                
                if (dp[i][j] && j - i + 1 > curMax) {
                    curMax = j - i + 1;
                    start = i;
                }
            }
        }
        
        return s.substr(start, curMax);
    }
};