#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> num = {0, 5, 2, 1, 4, 3};
    for (auto it = num.begin(); it != num.end(); it++)
        printf("%d ", *it);
    auto it = num.begin();
    printf("\n%d", *it);
    int x = *it++;
    printf("\n%d %d", x, *it);
    return 0;
}