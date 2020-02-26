#include "tools"
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, child = 0, cookie = 0;
        while (cookie < s.size() && child < g.size()) {
            while (cookie < s.size() && s[cookie] < g[child]) cookie++;
            if (cookie < s.size()) {cnt++; child++; cookie++;}
        }
        return cnt;
    }
};