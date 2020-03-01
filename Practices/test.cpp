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
    vector<vector<int>> res(3, vector<int>(4, 1));
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}