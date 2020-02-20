#include "tools"
class Solution {
public:
    string getHint(string secret, string guess) {
        // bull: 相同位置相同字符数, cow: 相同字符数 - bull
        int bull = 0, cow = 0;
        int bucket[10] = {0};
        size_t len = secret.length();
        for (int i = 0; i < len; i++) {
            if (guess[i] == secret[i]) {
                bull++;
                continue;
            }
            bucket[secret[i] - '0']++;
            bucket[guess[i] - '0']--;
        }
        for (int num : bucket)
            if (num > 0)
                cow += num;
        cow = len - cow - bull;
        return to_string(bull) + "A" + to_string(cow) + "B";
        
        // int bull = 0, cow = 0;
        // int secretNum[10] = {0}, checked[10] = {0};
        // size_t len = secret.length();
        // for (int i = 0; i < len; i++)
        //     secretNum[secret[i] - '0']++;
        // for (int i = 0; i < len; i++) {
        //     if (guess[i] == secret[i]) {
        //         bull++;
        //         checked[guess[i] - '0']++;
        //     }
        // }
        // for (int i = 0; i < len; i++) {
        //     if (guess[i] != secret[i] && checked[guess[i] - '0'] < secretNum[guess[i] - '0']) {
        //         cow++;
        //         checked[guess[i] - '0']++;
        //     }
        // }
        // return to_string(bull) + "A" + to_string(cow) + "B";
    }
};