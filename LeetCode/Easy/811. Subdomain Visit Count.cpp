#include "tools"
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hash;
        vector<string> res;
        for (string s : cpdomains) {
            size_t found = s.find(' ');
            int times = stoi(s.substr(0, found));
            string domain = s.substr(found + 1);
            while (found != string::npos) {
                hash[domain] += times;
                found = domain.find('.');
                domain = domain.substr(found + 1);
            }
        }
        for (auto key : hash)
            res.push_back(to_string(key.second) + " " + key.first);
        return res;
    }
};