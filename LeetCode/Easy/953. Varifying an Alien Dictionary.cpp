#include "tools"
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2) return true;
        unordered_map<char, int> val;
        for (int i = 0; i < order.length(); i++) val[order[i]] = i;
        for (int i = 1; i < words.size(); i++) {
            int len1 = words[i - 1].length(), len2 = words[i].length();
            int p = 0, q = 0;
            while (p < len1 && q < len2) {
                if (val[words[i - 1][p]] < val[words[i][q]]) break;
                if (val[words[i - 1][p]] > val[words[i][q]]) return false;
                p++, q++;
            }
            if (p < len1 && q == len2) return false;
        }
        return true;
    }
};