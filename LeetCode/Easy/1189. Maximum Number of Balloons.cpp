#include "tools"
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        unordered_set<char> balloon({'b', 'a', 'l', 'o', 'n'});
        for (char c : text)
            if (balloon.count(c)) count[c]++;
        if (count.size() < 5) return 0;
        int maxNum = INT_MAX;
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->first == 'l' || it->first == 'o')
                maxNum = min(maxNum, it->second / 2);
            else maxNum = min(maxNum, it->second);
        }
        return maxNum;
    }
};