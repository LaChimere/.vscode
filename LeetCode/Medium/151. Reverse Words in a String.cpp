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