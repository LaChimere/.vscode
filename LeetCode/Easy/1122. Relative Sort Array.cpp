#include "tools"
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int anchor = 0, cur;
        for (int check = 0; check < arr2.size(); check++) {
            for (cur = anchor; cur < arr1.size(); cur++) {
                if (arr1[cur] == arr2[check])
                    swap(arr1[anchor++], arr1[cur]);
            }
        }
        sort(arr1.begin() + anchor, arr1.end());
        return arr1;
    }
};