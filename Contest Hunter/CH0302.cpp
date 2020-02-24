#include <iostream>
#include <vector>
using namespace std;

vector<int> chosen;
void getEnum(int x, int n, int m) {
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m) return;
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); i++)
            printf("%d ", chosen[i]);
        puts("");
        return;
    }
    chosen.push_back(x);
    getEnum(x + 1, n, m);
    chosen.pop_back();
    getEnum(x + 1, n, m);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    getEnum(1, n, m);
    return 0;
}