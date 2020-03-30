#include <bits/stdc++.h>
using namespace std;

char g[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, -1, 0, 1};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            g[nx][ny] ^= 1;
    }
}

int work()
{
    int ans = INT_MAX;
    for (int k = 0; k < 1 << 5; k++)
    {
        int res = 0;
        char backup[10][10];
        memcpy(backup, g, sizeof(g));
        for (int j = 0; j < 5; j++)
        {
            if (k >> j & 1)
            {
                res++;
                turn(0, j);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (g[i][j] == '0')
                {
                    res++;
                    turn(i + 1, j);
                }
            }
        }
        bool isSuccessful = true;
        for (int j = 0; j < 5; j++)
        {
            if (g[4][j] == '0')
            {
                isSuccessful = false;
                break;
            }
        }
        if (isSuccessful) ans = min(ans, res);
        memcpy(g, backup, sizeof(backup));
    }
    return ans > 6 ? -1 : ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++) cin >> g[i];
        cout << work() << endl;
    }
    return 0;
}