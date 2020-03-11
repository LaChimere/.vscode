#include "tools"
class Solution {
private:
    static int lowbit(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n -= n & -n;
        }
        return cnt;
    }
    
    static bool cmp(int a, int b) {
        int la = lowbit(a), lb = lowbit(b);
        return la != lb ? la < lb : a < b;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};