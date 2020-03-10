#include "tools"
class Solution {
public:
    int balancedStringSplit(string s) {
        int record = 0, cnt = 0;
        for(char c : s){
            if(c == 'L') record--;
            else record++;
            if(record == 0) cnt++;
        }
        return cnt;

        // stack<char> st;
        // st.push(s[0]);
        // int i = 1, cnt = 0;
        // while (i < s.length()) {
        //     if (!st.empty()) {
        //         if (s[i] != st.top()) st.pop();
        //         else st.push(s[i]);
        //     } else {
        //         cnt++;
        //         st.push(s[i]);
        //     }
        //     i++;
        // }
        // return cnt + 1;
    }
};