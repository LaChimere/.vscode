#include "tools"
class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 1, right = 0;
        string res;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == '(') left++;
            else right++;
            if (right != left) res.push_back(S[i]);
            else i++, left = 1, right = 0;
        }
        return res;

        // if (S.empty()) return "";
        // stack<char> st;
        // string res;
        // int i = 0;
        // st.push(S[i++]);
        // while (i < S.length()) {
        //     if (S[i] == '(') {
        //         if (!st.empty()) res.push_back(S[i]);
        //         st.push(S[i]);
        //     } else {
        //         st.pop();
        //         if (!st.empty()) res.push_back(S[i]);
        //     }
        //     i++;
        // }
        // return res;
    }
};