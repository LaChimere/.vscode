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
    unordered_multiset<int> myset;
    myset.insert(3);
    myset.insert(5);
    myset.insert(3);
    for (auto it = myset.begin(); it != myset.end(); it++)
        cout << *it << " ";
    cout << endl;
    auto it = myset.find(4);
    myset.erase(it);
    for (auto it = myset.begin(); it != myset.end(); it++)
        cout << *it << " ";
    return 0;
}