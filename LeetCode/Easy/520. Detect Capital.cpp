#include "tools"
class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercase = 0;
        for (int i = 0; i < word.length(); i++)
            if (isupper(word[i]) && uppercase++ < i)
                return false;
        return uppercase == word.length() || uppercase <= 1;
        
        // if (word.length() <= 1) return true;
        // char firstLetter = word[0];
        // if (islower(firstLetter)) {
        //     for (int i = 1; i < word.length(); i++)
        //         if (isupper(word[i])) return false;
        // } else {
        //     char secondLetter = word[1];
        //     if (isupper(secondLetter)) {
        //         for (int i = 2; i < word.length(); i++)
        //             if (islower(word[i])) return false;
        //     } else {
        //         for (int i = 2; i < word.length(); i++)
        //             if (isupper(word[i])) return false;
        //     }
        // }
        // return true;
    }
};