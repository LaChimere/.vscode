#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1005;
bool safe[MAXSIZE];
int cnt[MAXSIZE];

int main()
{
    int n, k;
    cin >> n >> k;

    int unequal = 0;
    while (k--)
    {
        int p;
        cin >> p;

        vector<int> temp(2 * p);
        for (int i = 0; i < 2 * p; i++)
            cin >> temp[i];

        char relation;
        cin >> relation;

        if (relation == '=')
        {
            for (int i = 0; i < 2 * p; i++)
                safe[temp[i]] = true;
        }
        else if (relation == '>')
        {
            unequal++;
            for (int i = 0; i < p; i++)
                cnt[temp[i]]++;
            for (int i = p; i < 2 * p; i++)
                cnt[temp[i]]--;
        }
        else
        {
            unequal++;
            for (int i = 0; i < p; i++)
                cnt[temp[i]]--;
            for (int i = p; i < 2 * p; i++)
                cnt[temp[i]]++;
        }
    }

    int found = 0, coin = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!safe[i] && abs(cnt[i]) == unequal)
        {
            found++;
            coin = i;
        }
    }
    if (found != 1)
        cout << "0" << endl;
    else
        cout << coin << endl;

    return 0;
}