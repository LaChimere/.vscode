#include "tools"
class Solution {
public:
    string removeOuterParentheses(string S) {
        if (S.empty()) return "";
        stack<char> st;
        string res;
        int i = 0;
        st.push(S[i++]);
        while (i < S.length()) {
            if (S[i] == '(') {
                if (!st.empty()) res.push_back(S[i]);
                st.push(S[i]);
            } else {
                st.pop();
                if (!st.empty()) res.push_back(S[i]);
            }
            i++;
        }
        return res;
    }
};