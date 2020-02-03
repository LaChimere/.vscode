#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXSIZE = 2005;
map<string, int> string_to_int;
map<int, string> int_to_string;
map<string, int> gang;
int G[MAXSIZE][MAXSIZE] = {{0}}, pointWeight[MAXSIZE] = {0};
bool isVisited[MAXSIZE] = {false};

int idNum = 1;
int string_int(const string &s) {
    if (string_to_int[s] == 0) {
        string_to_int[s] = idNum;
        int_to_string[idNum] = s;
        return idNum++;
    } else
        return string_to_int[s];
}

void DFS(int u, int &head, int &numMember, int &totalWeight) {
    numMember++;
    isVisited[u] = true;
    if (pointWeight[u] > pointWeight[head])
        head = u;
    for (int i = 1; i < idNum; i++) {
        if (G[u][i] > 0) {
            totalWeight += G[u][i];
            G[u][i] = G[i][u] = 0;
            if (!isVisited[i])
                DFS(i, head, numMember, totalWeight);
        }
    }
}
int k;
void DFStraverse() {
    for (int i = 1; i < idNum; i++) {
        if (!isVisited[i]) {
            int head = i, numMember = 0, totalWeight = 0;
            DFS(i, head, numMember, totalWeight);
            if (numMember > 2 && totalWeight > k)
                gang[int_to_string[head]] = numMember;
        }
    }
}

int main() {
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = string_int(s1);
        int id2 = string_int(s2);
        pointWeight[id1] += w;
        pointWeight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFStraverse();
    cout << gang.size() << endl;
    for (auto it = gang.begin(); it != gang.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}