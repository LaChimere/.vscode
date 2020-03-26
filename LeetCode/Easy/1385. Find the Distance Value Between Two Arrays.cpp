#include "tools"
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int num : arr1) {
            int left = 0, right = len2 - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (num < arr2[mid]) right = mid;
                else left = mid + 1;
            }
            int a = arr2[right], b = arr2[max(0, right - 1)], c = arr2[min(len2 - 1, right + 1)];
            if (abs(num - a) > d && abs(num - b) > d && abs(num - c) > d) cnt++;
        }
        return cnt;
    }
};