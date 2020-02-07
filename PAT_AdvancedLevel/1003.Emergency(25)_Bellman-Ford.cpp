#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXSIZE = 505;
const int INF = 0x3fffffff;
struct edge {
    int v, length;
    edge(int _v, int _length): v(_v), length(_length) {}
};
vector<edge> adj[MAXSIZE];
set<int> pre[MAXSIZE];
int weight[MAXSIZE], dis[MAXSIZE], w[MAXSIZE] = {0}, num[MAXSIZE] = {0};
int n;
void Bellman(const int &s) {
    fill(dis, dis + n, INF);
    dis[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].v;
                int length = adj[u][j].length;
                if (dis[u] + length < dis[v]) {
                    dis[v] = dis[u] + length;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                } else if (dis[u] + length == dis[v]) {
                    if (w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                    pre[v].insert(u);
                    num[v] = 0;
                    for (auto it = pre[v].begin(); it != pre[v].end(); it++)
                        num[v] += num[*it];
                }
            }
        }
    }
}

int main() {
    int m, start, dest, city1, city2, length;
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &city1, &city2, &length);
        adj[city1].push_back(edge(city2, length));
        adj[city2].push_back(edge(city1, length));
    }
    Bellman(start);
    printf("%d %d", num[dest], w[dest]);
    return 0;
}