#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 110;
vector<int> children[MAXSIZE];
int n, m, res[MAXSIZE], maxDepth = -1;

void dfs(int id, int depth)
{
    if (children[id].empty())
    {
        res[depth]++;
        maxDepth = max(maxDepth, depth);
        return;
    }

    for (int child : children[id])
        dfs(child, depth + 1);
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

        dfs(1, 0);
        for (int i = 0; i <= maxDepth; i++)
        {
            cout << res[i];
            if (i < maxDepth)
                cout << " ";
        }
    }

    return 0;
}