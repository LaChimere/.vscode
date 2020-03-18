#include "tools"
class Solution {
private:
    int f(const string& s) {
        int cnt = 0;
        char small = 'z';
        for (char c : s) {
            if (c < small) {
                small = c;
                cnt = 1;
            } else if (c == small)
                cnt++;
        }
        return cnt;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res(queries.size()), count(12, 0);
        for (string w : words) count[f(w)]++;
        for (int i = 9; i > 0; i--) count[i] += count[i + 1];
        for (int i = 0; i < queries.size(); i++) res[i] = count[f(queries[i]) + 1];
        return res;
        
        // vector<int> W(words.size()), res(queries.size(), 0);
        // for (int i = 0; i < words.size(); i++) W[i] = f(words[i]);
        // for (int i = 0; i < queries.size(); i++) {
        //     int num = f(queries[i]);
        //     for (int w : W)
        //         if (w > num) res[i]++;
        // }
        // return res;
    }
};