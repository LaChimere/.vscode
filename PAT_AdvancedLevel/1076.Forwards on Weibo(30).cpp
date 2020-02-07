#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 1005;
int G[MAXSIZE][MAXSIZE] = {{0}};
bool inQueue[MAXSIZE] = {false};
int vLayer[MAXSIZE] = {0};

int n, L;
int BFS(int vNum) {
    int cnt = 0;
    queue<int> q;
    q.push(vNum);
    inQueue[vNum] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (!inQueue[i] && G[i][u] != 0) {
                vLayer[i] = vLayer[u] + 1;
                if (vLayer[i] >= 1 && vLayer[i] <= L) {
                    q.push(i);
                    cnt++;
                    inQueue[i] = true;
                }
            }
        }
    }
    return cnt;
}

void initState() {
    for (int i = 1; i <= n; i++) {
        vLayer[i] = 0;
        inQueue[i] = false;
    }
}

int main() {
    scanf("%d%d", &n, &L);
    int follows, temp, queries, queryNum;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &follows);
        for (int j = 0; j < follows; j++) {
            scanf("%d", &temp);
            G[i][temp] = 1;
        }
    }
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++) {
        scanf("%d", &queryNum);
        printf("%d\n", BFS(queryNum));
        if (i != queries - 1)
            initState();
    }
    return 0;
}