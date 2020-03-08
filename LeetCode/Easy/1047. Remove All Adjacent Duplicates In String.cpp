#include "tools"
class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> q;
        string res;
        q.push_back(S[0]);
        for (int i = 1; i < S.length(); i++) {
            if (!q.empty() && S[i] == q.back()) q.pop_back();
            else q.push_back(S[i]);
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
};