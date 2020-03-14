#include "tools"
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int one = 0;
        for (int i = bits.size() - 2; i >= 0 && bits[i] == 1; i--) one++;
        return one % 2 == 0;
        
        // int i;
        // for (i = 0; i < bits.size() - 1;) {
        //     if (bits[i] == 0) i++;
        //     else i += 2;
        // }
        // if (i >= bits.size()) return false;
        // return bits[i] == 0;
    }
};