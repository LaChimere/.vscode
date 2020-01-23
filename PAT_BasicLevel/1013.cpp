#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    vector<int> v;
    int cnt = 0, num = 2;
    while (cnt < n) {
        if (isPrime(num)) {
            cnt++;
            if (cnt >= m)
                v.push_back(num);
        }
        num++;
    }
    for (int i = 0; i < v.size(); i++) {
        if (i % 10 != 0)
            printf(" ");
        printf("%d", v[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    return 0;
}