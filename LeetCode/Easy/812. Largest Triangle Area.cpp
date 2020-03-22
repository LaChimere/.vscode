#include "tools"
class Solution {
private:
    double getArea(vector<int>& p, vector<int>& q, vector<int>& r) {
        return 0.5 * abs(p[0]*q[1] + q[0]*r[1] + r[0]*p[1] - p[1]*q[0] - q[1]*r[0] - r[1]*p[0]);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int len = points.size();
        double ans = 0.0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                for (int k = j + 1; k < len; k++)
                    ans = max(ans, getArea(points[i], points[j], points[k]));
        return ans;
    }
};