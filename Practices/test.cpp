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

int main() {
    vector<int> v{1, 3, 4, 5, 6, 0, 4, 8, 0, 2};
    auto it = v.begin();
    for (; it != v.end(); it++) {
        if (*it == 0) {
            auto temp = it;
            v.insert(it, 0);
            it = temp;
        }
    }
    for (int n : v)
        cout << n << " ";
    return 0;
}