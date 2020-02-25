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
    unordered_map<char, int> hash;
    hash['w'] = 2;
    cout << hash['w'];
    return 0;
}