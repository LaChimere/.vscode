#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v = {{0, 2}, {1, 2, 3}, {4, 6}};
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}