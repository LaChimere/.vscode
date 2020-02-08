#include "ignored"
class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
            return true;
        unordered_map<char, char> bracket = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        auto it = s.begin();
        while (s.length() != 0) {
            if (*it == '(' || *it == '[' || *it == '{') {
                st.push(*it);
                s.erase(s.begin());
            } else {
                if (!st.empty()) {
                    char temp = st.top();
                    st.pop();
                    if (temp != bracket[*it])
                        return false;
                    else s.erase(s.begin());
                } else return false;
            }
            it = s.begin();
        }
        if (st.empty()) return true;
        else return false;
    }
};