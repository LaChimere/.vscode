#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 200;
int cnt[MAXSIZE];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(cnt, 0, sizeof(cnt));
        int mostUse = 0;
        for (int i = 0; i < n; i++)
        {
            int start, dest, left, right;
            cin >> start >> dest;
            left = (min(start, dest) - 1) / 2;
            right = (max(start, dest) - 1) / 2;
            for (int k = left; k <= right; k++)
                mostUse = max(mostUse, ++cnt[k]);
        }
        cout << 10 * mostUse << endl;
    }

    return 0;
}