#include "tools"
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int minR = -1;
        for (int house : houses) {
            int left = 0, right = heaters.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int dis;
            if (heaters[left] == house) dis = 0;
            else if (heaters[left] < house) dis = house - heaters[left];
            else if (left > 0) dis = min(house - heaters[left - 1], heaters[left] - house);
            else dis = heaters[left] - house;
            if (dis > minR) minR = dis;
        }
        return minR;
    }
};