#include "tools"
class Solution {
private:
    unordered_multiset<string> countWords(string s) {
        unordered_multiset<string> res;
        size_t found = s.find(' ');
        while (found != string::npos) {
            res.insert(s.substr(0, found));
            s = s.substr(found + 1);
            found = s.find(' ');
        }
        res.insert(s);
        return res;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_multiset<string> wordsA(countWords(A)), wordsB(countWords(B));
        vector<string> res;
        for (auto s : wordsA)
            if (wordsA.count(s) == 1 && wordsB.count(s) == 0)
                res.push_back(s);
        for (auto s : wordsB)
            if (wordsB.count(s) == 1 && wordsA.count(s) == 0)
                res.push_back(s);
        return res;
    }
};