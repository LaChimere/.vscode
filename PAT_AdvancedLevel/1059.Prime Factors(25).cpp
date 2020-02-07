#include <iostream>
#include <vector>
using namespace std;

const int MAXNUM = 100000;
vector<bool> primes(MAXNUM, true);

int main() {
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if(n == 1) {
        printf("1");
        return 0;
    }
    for (int i = 2; i < MAXNUM; i++)
        for (int j = 2; j * i < MAXNUM; j++)
            primes[j * i] = false;
    bool flag = false;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        if (primes[i] && n % i == 0) {
            if (flag)
                printf("*");
            flag = true;
            printf("%d", i);
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            if (cnt > 1)
                printf("^%d", cnt);
        }
    }
    if (n > 1) {
        if (flag)
            printf("*");
        printf("%ld", n);
    }
    return 0;
}