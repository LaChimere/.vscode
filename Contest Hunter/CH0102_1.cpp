#include <iostream>
using namespace std;

int main() {
    long long a, b, p, res = 0LL;
    scanf("%lld %lld %lld", &a, &b, &p);
    while (b != 0) {
        if (b & 1)
            res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    printf("%lld", res);
    return 0;
}