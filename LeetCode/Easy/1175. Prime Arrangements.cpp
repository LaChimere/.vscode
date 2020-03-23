#include "tools"
class Solution {
private:
    const int MOD = 1e9 + 7;
    int getPrimes(int n) {
        if (n < 2) return 0;
        int cnt = 0;
        vector<int> isPrime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                cnt++;
                for (int j = i + i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
        return cnt;
    }
public:
    int numPrimeArrangements(int n) {
        int primes = getPrimes(n);
        int composites = n - primes;
        long long ans = 1;
        for (int i = 1; i <= primes; i++)
            ans = ans * i % MOD;
        for (int i = 1; i <= composites; i++)
            ans = ans * i % MOD;
        return ans;
    }
};