#include "tools"
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> sister;
        int cnt = 0;
        for (int candy : candies) {
            if (sister.find(candy) == sister.end()) {
                sister.insert(candy);
                cnt++;
            }
            if (cnt == (candies.size() >> 1)) return cnt;
        }
        return sister.size();
    }
};