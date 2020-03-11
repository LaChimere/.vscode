#include "tools"
class Solution {
private:
    void getPrimes(vector<bool>& primes) {
        primes[0] = false, primes[1] = false;
        for (int i = 2; i < primes.size(); i++) {
            if (primes[i])
                for (int j = i + i; j < primes.size(); j += i)
                    primes[j] = false;
        }
    }
    
    int lowbit(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n -= n & -n;
        }
        return cnt;
    }
public:
    int countPrimeSetBits(int L, int R) {
        vector<bool> primes(20, true);
        getPrimes(primes);
        int cnt = 0;
        for (int i = L; i <= R; i++)
            if (primes[lowbit(i)])
                cnt++;
        return cnt;
    }
};