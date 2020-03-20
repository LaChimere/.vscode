#include "tools"
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(), a.end());
        map<int, int> hash;
        int rank = 1;
        for (int i = 0; i < a.size(); i++) {
            if (i == 0) hash[a[i]] = rank++;
            else if (a[i] != a[i - 1]) hash[a[i]] = rank++;
        }
        for (int i = 0; i < arr.size(); i++)
            arr[i] = hash[arr[i]];
        return arr;
    }
};