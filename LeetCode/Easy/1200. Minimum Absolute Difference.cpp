#include "tools"
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int absDiff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < absDiff) {
                res.clear();
                absDiff = diff;
                res.push_back({arr[i - 1], arr[i]});
            } else if (diff == absDiff)
                res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};