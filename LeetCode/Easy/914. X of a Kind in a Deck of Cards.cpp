#include "tools"
class Solution {
private:
    int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> count(10000, 0);
        for (int num : deck) count[num]++;
        int g = 0;
        for (int cnt : count) {
            if (cnt) {
                if (g == 0) g = cnt;
                else g = gcd(g, cnt);
            }
        }
        return g >= 2;
        
        // vector<int> count(10000, 0);
        // for (int num : deck) count[num]++;
        // int minDivide = INT_MAX;
        // for (int cnt : count)
        //     if (cnt) minDivide = min(minDivide, cnt);
        // if (minDivide < 2) return false;
        // for (int x = 2; x <= minDivide; x++) {
        //     bool flag = true;
        //     for (int cnt : count)
        //         if (cnt && cnt % x) {
        //             flag = false;
        //             break;
        //         }
        //     if (flag) return true;
        // }
        // return false;
    }
};