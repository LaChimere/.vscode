#include <bits/stdc++.h>
using namespace std;

struct room {
    int j, f;
    double price;
};

bool cmp(const room& r1, const room& r2)
{
    return r1.price < r2.price;
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == -1 && n == -1)
            break;

        vector<room> rooms(n);
        for (int i = 0; i < n; i++)
        {
            cin >> rooms[i].j >> rooms[i].f;
            rooms[i].price = (double)rooms[i].f / rooms[i].j;
        }
        sort(rooms.begin(), rooms.end(), cmp);

        double gain = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (m >= rooms[i].f)
            {
                gain += rooms[i].j;
                m -= rooms[i].f;
            }
            else
            {
                gain += m / rooms[i].price;
                break;
            }
        }
        printf("%.3f\n", gain);
    }

    return 0;
}