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
    vector<int> v1({1, 2, 3}), v2({4, 5, 6});
    swap(v1, v2);
    for (int num : v1)
        cout << num << " ";
    return 0;
}