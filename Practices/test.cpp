#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <bitset>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    vector<vector<int>> count(501);
    int len = time.size(), cnt = 0;
    for (int i = 0; i < len; i++) count[time[i]].push_back(i);
    for (int i = 0; i < len; i++) {
        for (int k = 1; k <= 9; k++) {
            int check = k * 60 - time[i];
            if (check > 500) break;
            for (int j : count[check])
                if (i < j) cnt++;
        }
    }
    return cnt;
}