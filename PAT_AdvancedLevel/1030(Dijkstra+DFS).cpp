#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXSIZE = 505;
const int INF = 9999999;
struct edge {
    int length;
    int cost;
    edge() {
        length = INF;
        cost = INF;
    }
} e[MAXSIZE][MAXSIZE];
int n;
int dis[MAXSIZE];
bool isVisited[MAXSIZE] = {false};
vector<int> pre[MAXSIZE];
int Dijkstra(const int &startCity, const int &destCity) {
    fill(dis, dis + n, INF);
    dis[startCity] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, nowMin = INF;
        for (int j = 0; j < n; j++) {
            if (!isVisited[j] && dis[j] < nowMin) {
                u = j;
                nowMin = dis[j];
            }
        }
        if (u == -1) break;
        isVisited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!isVisited[v] && e[u][v].length != INF) {
                if (dis[u] + e[u][v].length < dis[v]) {
                    dis[v] = dis[u] + e[u][v].length;
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + e[u][v].length == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    return dis[destCity];
}
vector<int> path, tempPath;
void DFS(int s, int v, int &minCost) {
    if (v == s) {
        tempPath.push_back(v);
        int nowCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--)
            nowCost += e[tempPath[i]][tempPath[i - 1]].cost;
        if (nowCost < minCost) {
            minCost = nowCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
        DFS(s, pre[v][i], minCost);
    tempPath.pop_back();
}

int main() {
    int m, start, dest, city1, city2;
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &city1, &city2);
        scanf("%d%d", &e[city1][city2].length, &e[city1][city2].cost);
        e[city2][city1].length = e[city1][city2].length;
        e[city2][city1].cost = e[city1][city2].cost;
    }
    int totalDist = Dijkstra(start, dest);
    int totalCost = INF;
    DFS(start, dest, totalCost);
    for (int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", totalDist, totalCost);
    return 0;
}