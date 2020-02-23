#include <iostream>
#include <cstring>
using namespace std;

const int MAXSIZE = 20;
int n, G[MAXSIZE][MAXSIZE], dp[1 << MAXSIZE][MAXSIZE];

int Hamilton() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if ((i ^ 1 << j) >> k & 1)
                        dp[i][j] = min(dp[i][j], dp[i ^ 1 << j][k] + G[k][j]);
    return dp[(1 << n) - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
    cout << Hamilton();
    return 0;
}