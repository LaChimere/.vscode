#include "tools"
class Solution {
private:
    unordered_map<string, int> words;
    void getWords(const string& s) {
        string word;
        for (int cur = 0; cur < s.length(); cur++) {
            if (isalpha(s[cur])) {
                word.push_back(tolower(s[cur]));
            } else if (!word.empty()) {
                words[word]++;
                word.clear();
            }
        }
        if (!word.empty()) words[word]++;
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        getWords(paragraph);
        unordered_set<string> bannedWords;
        for (string& s : banned) bannedWords.insert(s);
        int frequences = 0;
        string res;
        for (auto it = words.begin(); it != words.end(); it++) {
            if (!bannedWords.count(it->first) && it->second > frequences) {
                frequences = it->second;
                res = it->first;
            }
        }
        return res;
    }
};