#include "tools"
class Solution {
private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] - v1[0] < v2[1] - v2[0];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0, n = costs.size() / 2;
        sort(costs.begin(), costs.end(), cmp);
        for (int i = 0; i < n; i++) sum += costs[i][1] + costs[i + n][0];
        return sum;
    }
};