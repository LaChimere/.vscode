#include <iostream>
using namespace std;

int main() {
    long long a, b, p, res;
    scanf("%lld %lld %lld", &a, &b, &p);
    a %= p, b %= p;
    long long c = (long double)a * b / p;
    res = a * b - c * p;
    if (res < 0) res += p;
    else if (res >= p) res %= p;
    printf("%lld", res);
    return 0;
}