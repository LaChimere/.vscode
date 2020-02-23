#include <iostream>
using namespace std;

const int MAXSIZE = 100005;
struct door {
    string op;
    int t;
} doors[MAXSIZE];

int cal(int bit, int now, int n) {
    for (int i = 1; i <= n; i++) {
        int x = doors[i].t >> bit & 1;
        if (doors[i].op == "AND") now &= x;
        else if (doors[i].op == "OR") now |= x;
        else now ^= x;
    }
    return now;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> doors[i].op >> doors[i].t;
    int val = 0, ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        int res0 = cal(bit, 0, n), res1 = cal(bit, 1, n);
        if (val + (1 << bit) <= m && res0 < res1) {
            val += 1 << bit;
            ans += res1 << bit;
        } else ans += res0 << bit;
    }
    cout << ans;
    return 0;
}