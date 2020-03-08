#include "tools"
class Solution {
private:
    void getRes(stack<char>& st, const string& str) {
        for (char c : str) {
            if (!st.empty() && c == '#')
                st.pop();
            else if (c != '#')
                st.push(c);
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        getRes(s, S);
        getRes(t, T);
        if (s.size() != t.size()) return false;
        while (!s.empty() && !t.empty()) {
            if (s.top() != t.top()) return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};