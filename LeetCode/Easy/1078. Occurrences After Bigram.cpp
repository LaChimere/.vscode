#include "tools"
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> words;
        size_t found = text.find(' ');
        while (found != string::npos) {
            words.push_back(text.substr(0, found));
            text = text.substr(found + 1);
            found = text.find(' ');
        }
        words.push_back(text);
        if (words.size() < 3) return res;
        for (int i = 2; i < words.size(); i++)
            if (words[i - 2] == first && words[i - 1] == second)
                res.push_back(words[i]);
        return res;
    }
};