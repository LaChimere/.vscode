#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        stringstream ss(s);
        string res, temp;
        while (ss >> temp) st.push(temp);
        while (!st.empty()) {
            res += st.top() + " ";
            st.pop();
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};

class Solution2 {
public:
    string reverseWords(string s) {
        while (!s.empty() && s.front() == ' ') s.erase(s.begin());
        while (!s.empty() && s.back() == ' ') s.erase(s.begin() + s.length() - 1);
        int anchor = s.length(), cur;
        string res;
        for (cur = s.length() - 1; cur >= 0; cur--) {
            if (cur == 0) {
                res += string(s.begin(), s.begin() + anchor);
                continue;
            }
            if (s[cur] != ' ') continue;
            res += string(s.begin() + cur + 1, s.begin() + anchor) + " ";
            while (cur >= 0 && s[cur] == ' ') cur--;
            anchor = ++cur;
        }
        return res;
    }
};