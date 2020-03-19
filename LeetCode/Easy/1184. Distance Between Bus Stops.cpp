#include "tools"
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int i = start, j = start, dist1 = 0, dist2 = 0, n = distance.size();
        while (true) {
            if (i != destination) {
                dist1 += distance[i];
                i = (i + 1) % n;
            }
            if (j != destination) {
                j = (n - 1 + j) % n;
                dist2 += distance[j];
            }
            if (i == destination && j == destination) break;
        }
        return dist1 < dist2 ? dist1 : dist2;
    }
};