#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int update(const string& s, vector<int>& p)
    {
        int state = 0, res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case 'a':
                    state ^= 1;
                    break;
                case 'e':
                    state ^= 1 << 1;
                    break;
                case 'i':
                    state ^= 1 << 2;
                    break;
                case 'o':
                    state ^= 1 << 3;
                    break;
                case 'u':
                    state ^= 1 << 4;
                    break;
                default:
                    break;
            }
            
            if (p[state] == INT_MAX)
                p[state] = i;
            else
                res = max(res, i - p[state]);
        }
        return res;
    }
public:
    int findTheLongestSubstring(string s) {
        vector<int> p(32, INT_MAX);
        p[0] = -1;
        
        return update(s, p);
    }
};