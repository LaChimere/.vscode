#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> num = {0, 3, 2, 3, 4, 3};
    for (int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    return 0;
}