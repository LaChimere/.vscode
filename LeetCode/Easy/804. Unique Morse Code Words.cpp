#include "tools"
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse({
            ".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-",
            "-.--","--.."
        });
        unordered_set<string> trans;
        for (string& word : words) {
            string res;
            for (char& c : word) res += morse[c - 'a'];
            trans.insert(res);
        }
        return trans.size();
    }
};