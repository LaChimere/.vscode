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
using namespace std;

int main() {
    set<int> myset({1,2,3,5,4,8,6});
    auto it = myset.rbegin();
    it++;
    it++;
    cout << *it;
    return 0;
}