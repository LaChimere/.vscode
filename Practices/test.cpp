#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v(3, 100);
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    v.insert(v.begin(), 200);
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    return 0;
}