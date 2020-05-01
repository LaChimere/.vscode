#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 110;
vector<int> children[MAXSIZE];
int n, m, res[MAXSIZE];

void bfs()
{
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    int maxLevel = -1;
    while (!q.empty())
    {
        auto [id, level] = q.front();
        q.pop();
        maxLevel = max(maxLevel, level);
        if (children[id].empty())
            res[level]++;
        for (int child : children[id])
            q.emplace(child, level + 1);
    }

    cout << res[0];
    for (int i = 1; i <= maxLevel; i++)
        cout << " " << res[i];
}

int main()
{
    while (cin >> n >> m && n != 0)
    {
        int id, k, child;
        for (int i = 0; i < m; i++)
        {
            cin >> id >> k;
            for (int j = 0; j < k; j++) {
                cin >> child;
                children[id].push_back(child);
            }
        }

        bfs();
    }

    return 0;
}