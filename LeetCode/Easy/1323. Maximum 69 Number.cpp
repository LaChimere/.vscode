#include "tools"
class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        size_t found = n.find('6');
        if (found == string::npos) return num;
        n[found] = '9';
        return stoi(n);
    }
};