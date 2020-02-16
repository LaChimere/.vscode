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
    unordered_set<int> myset;
    cout << myset.size() << endl;
    myset.insert(1);
    myset.insert(3);
    myset.insert(4);
    for (auto it = myset.begin(); it != myset.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << myset.count(2);
    return 0;
}