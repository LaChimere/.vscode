#include <iostream>
#include <vector>
using namespace std;

vector<int> chosen;
void getEnum(int x, int n) {
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); i++)
            printf("%d ", chosen[i]);
        puts("");
        return;
    }
    getEnum(x + 1, n);
    chosen.push_back(x);
    getEnum(x + 1, n);
    chosen.pop_back();
}

int main() {
    int n;
    scanf("%d", &n);
    getEnum(1, n);
    return 0;
}