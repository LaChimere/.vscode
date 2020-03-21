#include "tools"
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        for (char c : licensePlate) {
            if (isupper(c)) cnt[tolower(c) - 'a']++;
            else if (islower(c)) cnt[c - 'a']++;
        }
        string res;
        int len = INT_MAX;
        for (string word : words) {
            vector<int> check(26, 0);
            for (char c : word) check[c - 'a']++;
            int i;
            for (i = 0; i < 26; i++)
                if (check[i] < cnt[i]) break;
            if (i == 26 && word.length() < len) {
                res = word;
                len = word.length();
            }
        }
        return res;
    }
};