#include "tools"
class Solution {
private:
    static bool cmp(const string& s1, const string& s2) {
        size_t found1 = s1.find(' '), found2 = s2.find(' ');
        if (isalpha(s1.substr(found1 + 1).at(0)) && isalpha(s2.substr(found2 + 1).at(0)))
            return
                s1.substr(found1 + 1) != s2.substr(found2 + 1) ?
                s1.substr(found1 + 1) < s2.substr(found2 + 1)
                : s1.substr(0, found1) < s2.substr(0, found2);
        return isalpha(s1.substr(found1 + 1).at(0));
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};