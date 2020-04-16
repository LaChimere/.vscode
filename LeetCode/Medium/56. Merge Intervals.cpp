#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool overlap(const vector<int>& p1, const vector<int>& p2) {
        return !(p1[1] < p2[0] || p2[1] < p1[0]);
    }
    
    static bool cmp(const vector<int>& p1, const vector<int>& p2) {
        return p1[0] != p2[0] ? p1[0] < p2[0] : p1[1] < p2[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty()) res.emplace_back(intervals[i]);
            else if (overlap(intervals[i], res[res.size() - 1])) {
                int s = min(intervals[i][0], res[res.size() - 1][0]);
                int e = max(intervals[i][1], res[res.size() - 1][1]);
                res.pop_back();
                res.push_back({s, e});
            }
            else res.emplace_back(intervals[i]);
        }
        return res;
    }
};