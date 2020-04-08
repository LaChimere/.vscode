#include <bits/stdc++.h>
using namespace std;

struct tvshow {
    int s, e;
};

bool cmp(const tvshow& a, const tvshow& b)
{
    return a.e < b.e;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<tvshow> shows(n);
        for (int i = 0; i < n; i++)
            cin >> shows[i].s >> shows[i].e;
        sort(shows.begin(), shows.end(), cmp);

        int cnt = 0, preTi_e = 0;
        for (const auto& show : shows)
        {
            if (show.s >= preTi_e)
            {
                cnt++;
                preTi_e = show.e;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}