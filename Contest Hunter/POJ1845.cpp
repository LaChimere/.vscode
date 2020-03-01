#include <iostream>
#include <vector>
using namespace std;

const int MAXSIZE = 10000, MOD = 9901;
vector<int> primes;
vector<bool> isPrime(MAXSIZE, true);
struct factor {
    int prime, cnt;
    factor(int _prime, int _cnt = 0) : prime(_prime), cnt(_cnt) {}
};
vector<factor> fac;

void getPrimes() {
    for (int i = 2; i < MAXSIZE; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAXSIZE; j += i)
                isPrime[j] = false;
        }
    }
}

void getFactors(int n) {
    for (int i = 0; i < primes.size() && primes[i] <= n / primes[i]; i++) {
        if (n % primes[i] == 0) {
            factor cur(primes[i]);
            while (n % primes[i] == 0) {
                cur.cnt++;
                n /= primes[i];
            }
            fac.push_back(cur);
        }
    }
    if (n > 1) {
        factor cur(n, 1);
        fac.push_back(cur);
    }
}

long long power(int a, int b) {
    long long ret = 1LL;
    while (b) {
        if (b & 1)
            ret = (long long)ret * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int sum(long long p, long long c) {
    if (c == 0) return 1;
    if (c % 2 == 1) return ((1 + power(p, (c + 1) >> 1)) * sum(p, (c - 1) >> 1)) % MOD;
    else return ((1 + power(p, c >> 1)) * sum(p, (c >> 1) - 1) + power(p, c)) % MOD;
}

int main() {
    int A, B;
    getPrimes();
    while (cin >> A >> B) {
        getFactors(A);
        int ans = 1;
        for (int i = 0; i < fac.size(); i++) {
            fac[i].cnt *= B;
            ans = (ans * sum(fac[i].prime, fac[i].cnt)) % MOD;
        }
        cout << ans << endl;
        fac.clear();
    }
    return 0;
}