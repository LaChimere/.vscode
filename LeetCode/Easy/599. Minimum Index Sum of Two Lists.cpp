#include "tools"
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) swap(list1, list2);
        unordered_map<string, int> rests1;
        for (int i = 0; i < list1.size(); i++) rests1[list1[i]] = i;
        int minSum = INT_MAX;
        vector<string> minRests;
        for (int i = 0; i < list2.size(); i++) {
            if (rests1.find(list2[i]) != rests1.end()) {
                if (i + rests1[list2[i]] < minSum) {
                    minSum = i + rests1[list2[i]];
                    minRests.clear();
                    minRests.push_back(list2[i]);
                } else if (i + rests1[list2[i]] == minSum) {
                    minRests.push_back(list2[i]);
                }
            }
        }
        return minRests;
    }
};