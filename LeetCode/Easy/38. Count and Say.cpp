#include "tools"
class Solution {
public:
    string countAndSay(int n) {
        string str[31];
        str[1] = "1";
        for (int i = 2; i < 31; i++) {
            char c = str[i-1][0];
            int cnt = 1;
            for (int j = 1; j < str[i-1].length(); j++) {
                if (c == str[i-1][j]) {
                    cnt++;
                } else {
                    str[i].push_back(cnt + '0');
                    str[i].push_back(c);
                    c = str[i-1][j];
                    cnt = 1;
                }
            }
            str[i].push_back(cnt + '0');
            str[i].push_back(c);
        }
        return str[n];
    }
};