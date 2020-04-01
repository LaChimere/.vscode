#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.length());
        int idx = 0;
        for (const char& c : seq)
            res[idx++] = idx & 1 ^ (c == '(');
        return res;
    }
};