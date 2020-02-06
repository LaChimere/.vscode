#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 505;
const int INF = 9999999;
int G[MAXSIZE][MAXSIZE];
bool isVisited[MAXSIZE] = {false};
int dis[MAXSIZE];
int shortestNum[MAXSIZE] = {0};
int cityTeams[MAXSIZE] = {0};
int team[MAXSIZE] = {0};
int cities;
int Dijkstra(const int &startCity, const int &destCity, int &teams) {
    fill(dis, dis + cities, INF);
    dis[startCity] = 0;
    shortestNum[startCity] = 1;
    team[startCity] = cityTeams[startCity];
    for (int i = 0; i < cities; i++) {
        int u = -1, nowMin = INF;
        for (int j = 0; j < cities; j++) {
            if (!isVisited[j] && dis[j] < nowMin) {
                nowMin = dis[j];
                u = j;
            }
        }
        if (u == -1) break;
        isVisited[u] = true;
        for (int v = 0; v < cities; v++) {
            if (!isVisited[v] && G[u][v] != INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    team[v] = team[u] + cityTeams[v];
                    shortestNum[v] = shortestNum[u];
                } else if (dis[u] + G[u][v] == dis[v]) {
                    shortestNum[v] += shortestNum[u];
                    if (team[u] + cityTeams[v] > team[v])
                        team[v] = team[u] + cityTeams[v];
                }
            }
        }
    }
    teams = team[destCity];
    return shortestNum[destCity];
}

int main() {
    int m, start, dest, gatheredTeams, city1, city2;
    scanf("%d%d%d%d", &cities, &m, &start, &dest);
    fill(G[0], G[0] + MAXSIZE * MAXSIZE, INF);
    for (int i = 0; i < cities; i++)
        scanf("%d", &cityTeams[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &city1, &city2);
        scanf("%d", &G[city1][city2]);
        G[city2][city1] = G[city1][city2];
    }
    int shortestRoads = Dijkstra(start, dest, gatheredTeams);
    printf("%d %d", shortestRoads, gatheredTeams);
    return 0;
}