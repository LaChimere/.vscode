#include <iostream>
using namespace std;

int d[13], f[13];

int main() {
    d[1] = 1;
    for (int i = 2; i <= 12; i++) {
        d[i] = 2 * d[i - 1] + 1;
    }
    f[1] = 1;
    cout << f[1] << endl;
    for (int num = 2; num <= 12; num++) {
        int minAns = 0x3f3f3f3f;
        for (int i = 1; i < num; i++) {
            minAns = min(minAns, 2 * f[i] + d[num - i]);
        }
        f[num] = minAns;
        cout << f[num] << endl;
    }
    return 0;
}