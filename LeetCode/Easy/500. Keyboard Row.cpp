#include "tools"
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> lines({"qwertyuiop", "asdfghjkl", "zxcvbnm"});
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            char startLine = tolower(words[i][0]);
            string checkLine;
            for (int j = 0; j < 3; j++)
                if (lines[j].find(startLine) != string::npos) checkLine = lines[j];
            int k;
            for (k = 1; k < words[i].length(); k++)
                if (checkLine.find(tolower(words[i][k])) == string::npos) break;
            if (k == words[i].length()) res.push_back(words[i]);
        }
        return res;
    }
};