#include <iostream>
#include <vector>
using namespace std;

vector<int> order;
vector<bool> isChosen(10, false);
void getEnum(int x, int n) {
    if (x == n + 1) {
        for (int i = 0; i < order.size(); i++)
            printf("%d ", order[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!isChosen[i]) {
            order.push_back(i);
            isChosen[i] = true;
            getEnum(x + 1, n);
            order.pop_back();
            isChosen[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getEnum(1, n);
    return 0;
}