#include "tools"
class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
            return true;
        unordered_map<char, char> bracket = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        while (s.length() != 0) {
            if (*s.begin() == '(' || *s.begin() == '[' || *s.begin() == '{') {
                st.push(*s.begin());
                s.erase(s.begin());
            } else {
                if (!st.empty()) {
                    char temp = st.top();
                    st.pop();
                    if (temp != bracket[*s.begin()])
                        return false;
                    else s.erase(s.begin());
                } else return false;
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};