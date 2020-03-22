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
    bitset<32> num = bitset<32>(5);
    int k = 0;
    for (int i = 0; i < 32; i++) {
        cout << num[i];
        k = (k + 1) % 4;
        if (k == 0) cout << " ";
    }
    return 0;
}