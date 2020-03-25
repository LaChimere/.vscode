#include "tools"
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (char c : address) {
            if (c != '.') res.push_back(c);
            else res += "[.]";
        }
        return res;
    }
};