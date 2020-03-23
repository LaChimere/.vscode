#include "tools"
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.length() && j < typed.length()) {
            if (name[i] == typed[j]) i++, j++;
            else while (j < typed.length() && name[i] != typed[j]) j++;
        }
        return i == name.length();
    }
};