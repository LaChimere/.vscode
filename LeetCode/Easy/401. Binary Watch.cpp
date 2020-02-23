#include "tools"
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 60; j++)
                if (cal(i) + cal(j) == num)
                    ret.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
        return ret;
    }
    
    int cal(int x) {
        int n = 0;
        while (x != 0){
            x -= lowbit(x);
            n++;
        }
        return n;
    }
    
    int lowbit(int x) {
        return x & -x;
    }
};