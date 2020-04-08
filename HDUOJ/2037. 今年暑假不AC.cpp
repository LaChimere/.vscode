#include <bits/stdc++.h>
using namespace std;

struct tvshow {
    int s, e, t;
};

bool cmp(const tvshow& a, const tvshow& b)
{
    return a.t != b.t ? a.t < b.t : a.s < b.s;
}

bool overlap(const vector<pair<int, int> >& intervals, const int& ti_s, const int& ti_e)
{
    for (const auto& cur : intervals)
        if (!(cur.first >= ti_e || cur.second <= ti_s))
            return true;
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<tvshow> shows(n);
        for (int i = 0; i < n; i++)
        {
            cin >> shows[i].s >> shows[i].e;
            shows[i].t = shows[i].e - shows[i].s;
        }
        sort(shows.begin(), shows.end(), cmp);

        int cnt = 0;
        vector<pair<int, int> > occupied;
        for (int i = 0; i < n; i++)
        {
            if (!overlap(occupied, shows[i].s, shows[i].e))
            {
                cnt++;
                occupied.emplace_back(shows[i].s, shows[i].e);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}