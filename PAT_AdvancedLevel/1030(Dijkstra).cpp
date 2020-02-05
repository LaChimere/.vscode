#include <iostream>
#include <algorithm>
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
int pre[MAXSIZE], dis[MAXSIZE], cost[MAXSIZE];
bool isVisited[MAXSIZE] = {false};
int Dijkstra(const int &startCity, const int &destCity, int &totalCost) {
    fill(dis, dis + n, INF);
    fill(cost, cost + n, INF);
    dis[startCity] = 0;
    cost[startCity] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, nowMin = INF;
        for (int j = 0; j < n; j++) {
            if (!isVisited[j] && e[i][j].length < nowMin) {
                u = j;
                nowMin = e[i][j].length;
            }
        }
        if (u == -1) break;
        isVisited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!isVisited[v] && e[u][v].length != INF) {
                if (dis[u] + e[u][v].length < dis[v]) {
                    dis[v] = dis[u] + e[u][v].length;
                    pre[v] = u;
                    cost[v] = cost[u] + e[u][v].cost;
                } else if (dis[u] + e[u][v].length == dis[v]) {
                    if (cost[u] + e[u][v].cost < cost[v]) {
                        pre[v] = u;
                        cost[v] = cost[u] + e[u][v].cost;
                    }
                }
            }
        }
    }
    totalCost = cost[destCity];
    return dis[destCity];
}
void printPath(int s, int v) {
    if (s == v) {
        printf("%d ", v);
        return;
    }
    printPath(s, pre[v]);
    printf("%d ", v);
}

int main() {
    int m, start, dest, city1, city2, totalDist, totalCost;
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &city1, &city2);
        scanf("%d%d", &e[city1][city2].length, &e[city1][city2].cost);
        e[city2][city1].length = e[city1][city2].length;
        e[city2][city1].cost = e[city1][city2].cost;
    }
    totalDist = Dijkstra(start, dest, totalCost);
    printPath(start, dest);
    printf("%d %d", totalDist, totalCost);
    return 0;
}