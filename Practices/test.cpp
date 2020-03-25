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
    string s = "jinlingxia";
    auto it = s.begin();
    while (*it != 'l')
        it++;
    s.erase(it);
    cout << *it;
    return 0;
}