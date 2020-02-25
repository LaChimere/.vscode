#include "tools"
class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.size(); read++) {
            if (read == chars.size() - 1 || chars[read + 1] != chars[read]) {
                chars[write++] = chars[anchor];
                if (read > anchor) {
                    for (char c : to_string(read - anchor + 1))
                        chars[write++] = c;
                }
                anchor = read + 1;
            }
        }
        return write;
        
        // int cnt = 1;
        // char nowCheck = chars[0];
        // auto it = chars.begin() + 1;
        // while (it != chars.end()) {
        //     if (*it == nowCheck) {
        //         cnt++;
        //         chars.erase(it);
        //     } else {
        //         int k = 0;
        //         if (cnt != 1) {
        //             while (cnt != 0) {
        //                 chars.insert(it, cnt % 10 + '0');
        //                 k++;
        //                 cnt /= 10;
        //             }
        //         }
        //         while (it != chars.end() && k--) it++;
        //         nowCheck = *it++;
        //         cnt = 1;
        //     }
        // }
        // if (cnt != 1) {
        //     while (cnt != 0) {
        //         chars.insert(it, cnt % 10 + '0');
        //         cnt /= 10;
        //     }
        // }
        // return chars.size();
    }
};