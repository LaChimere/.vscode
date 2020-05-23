#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        int cnt = 0;
        unordered_map<char, int> m;
        for (char c : t)
            m[c]++, cnt++;

        size_t len = s.length(), start = 0;
        bool flag = false;
        for (int i = 0, j = -1; i < s.length(); ++i) {
            if (m.find(s[i]) != m.end() && --m[s[i]] >= 0)
                cnt--;
            while (cnt == 0 && j < i) {
                flag = true;
                if (i - j < len) {
                    start = j + 1;
                    len = i - j;
                }
                char c = s[++j];
                if (m.find(c) != m.end() && ++m[c] > 0)
                    cnt++;
            }
        }

        return flag ? s.substr(start, len) : "";
    }
};