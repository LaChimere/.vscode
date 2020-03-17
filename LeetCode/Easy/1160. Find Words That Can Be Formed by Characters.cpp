#include "tools"
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> letters(26, 0);
        for (char c : chars) letters[c - 'a']++;
        int sum = 0;
        for (string s : words) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;
            int i;
            for (i = 0; i < 26; i++)
                if (count[i] > letters[i]) break;
            if (i == 26) sum += s.length();
        }
        return sum;
    }
};