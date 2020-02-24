#include <iostream>
using namespace std;

int state[7][7], f[7][7];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int minAns = 0x7fffffff;
        getchar();
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                char c = getchar();
                state[i][j] = c - '0';
            }
            getchar();
        }
        for (int k = 0; k <= (1 << 5); k++) {
            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++)
                    f[i][j] = state[i][j];
            }
            int ans = 0;
            for (int j = 1; j <= 5; j++) {
                if (k >> (j - 1) & 1) {
                    ans++;
                    f[1][j] ^= 1;
                    f[1][j - 1] ^= 1;
                    f[1][j + 1] ^= 1;
                    f[2][j] ^= 1;
                }
            }
            for (int i = 1; i < 5; i++)
                for (int j = 5; j >= 1; j--) {
                    if (!f[i][j]) {
                        ans++;
                        f[i + 1][j] ^= 1;
                        f[i][j] ^= 1;
                        f[i + 2][j] ^= 1;
                        f[i + 1][j - 1] ^= 1;
                        f[i + 1][j + 1] ^= 1;
                    }
                }
            bool flag = true;
            for (int i = 1; i <= 5; i++)
                for (int j = 1; j <= 5; j++)
                    if (!f[i][j]) flag = false;
            if (flag) minAns = ans < minAns ? ans : minAns;
        }
        printf("%d\n", minAns <= 6 ? minAns : -1);
    }
    return 0;
}