#include "tools"
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size(), cnt = 0;
        flowerbed.insert(flowerbed.begin(), 1, 0);
        flowerbed.push_back(0);
        for (int i = 1; i <= len; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                cnt++;
                flowerbed[i] = 1;
            }
            if (n <= cnt) return true;
        }
        return false;
    }
};