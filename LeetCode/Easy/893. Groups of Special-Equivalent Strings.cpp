#include "tools"
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int len = A[0].length();
        unordered_set<string> res;
        for (string& s : A) {
            string odd, even;
            for (int i = 0; i < len; i++) {
                if (i & 1) odd.push_back(s[i]);
                else even.push_back(s[i]);
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            res.insert(odd + even);
        }
        return res.size();
        
        // int n = A.size(), len = A[0].length();
        // vector<vector<int>> odd(n, vector<int>(26, 0)), even(n, vector<int> (26, 0));
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < len; j++) {
        //         if (j & 1) odd[i][A[i][j] - 'a']++;
        //         else even[i][A[i][j] - 'a']++;
        //     }
        // set<pair<vector<int>, vector<int>>> res;
        // for (int i = 0; i < n; i++) res.insert({odd[i], even[i]});
        // return res.size();
    }
};