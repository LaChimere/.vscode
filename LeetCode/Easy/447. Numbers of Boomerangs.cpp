#include "tools"
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < points.size(); i++) {
            hash.clear();
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                if (hash.find(d) != hash.end()) {
                    res += hash[d] * 2;
                    hash[d] += 1;
                } else hash[d] = 1;
            }
        }
        return res;
    }
};