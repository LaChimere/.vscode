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
    vector<int> v({0, 1, 2, 3});
    for (int n : v) cout << n << " ";
    cout << endl;
    for (int n : v) n++;
    for (int n : v) cout << n << " ";
    cout << endl;
    for (int& n : v) n++;
    for (int n : v) cout << n << " ";
    return 0;
}