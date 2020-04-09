#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(string cur, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.emplace_back(cur);
            return;
        }
        if (left > right) return;
        if (left > 0)
            dfs(cur + '(', left - 1, right, res);
        if (right > 0)
            dfs(cur + ')', left, right - 1, res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        dfs("", n, n, res);
        return res;
    }
};