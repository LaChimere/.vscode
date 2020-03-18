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
        vector<int> W(words.size()), res(queries.size(), 0);
        for (int i = 0; i < words.size(); i++) W[i] = f(words[i]);
        for (int i = 0; i < queries.size(); i++) {
            int num = f(queries[i]);
            for (int w : W)
                if (w > num) res[i]++;
        }
        return res;
    }
};