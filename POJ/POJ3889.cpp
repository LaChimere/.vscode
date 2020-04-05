#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n, LL m)
{
    if (n == 0) return {0, 0};
    LL len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);
    auto pos = calc(n - 1, m % cnt);
    LL x = pos.first, y = pos.second;
    LL z = m / cnt;
    if (z == 0) return {y, x};
    if (z == 1) return {x, y + len};
    if (z == 2) return {x + len, y + len};
    return {2 * len - 1 - y, len - 1 - x};
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        LL N, A, B;
        cin >> N >> A >> B;
        auto a = calc(N, A - 1);
        auto b = calc(N, B - 1);
        double x = a.first - b.first, y = a.second - b.second;
        printf("%.0lf\n", 10 * sqrt(x * x + y * y));
    }
    return 0;
}