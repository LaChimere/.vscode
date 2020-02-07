#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXSIZE = 105;
struct BiTree {
    int weight;
    vector<int> child;
} tree[MAXSIZE];
int path[MAXSIZE];

bool cmp(const int &a, const int &b) {
    return tree[a].weight > tree[b].weight;
}

void createBiTree(int nodeNums, int nonLeafNodeNums) {
    for (int i = 0; i < nodeNums; i++)
        scanf("%d", &tree[i].weight);
    for (int i = 0; i < nonLeafNodeNums; i++) {
        int num, childNums, childNum;
        scanf("%d%d", &num, &childNums);
        for (int j = 0; j < childNums; j++) {
            scanf("%d", &childNum);
            tree[num].child.push_back(childNum);
        }
        sort(tree[num].child.begin(), tree[num].child.end(), cmp);
    }
}

void DFS(int index, int nodeNum, int sum, const int &s) {
    if (sum > s) return;
    if (sum == s) {
        if (tree[index].child.size() != 0) return;
        for (int i = 0; i < nodeNum; i++) {
            printf("%d", tree[path[i]].weight);
            if (i < nodeNum - 1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for (int i = 0; i < tree[index].child.size(); i++) {
        int childNum = tree[index].child[i];
        path[nodeNum] = childNum;
        DFS(childNum, nodeNum + 1, sum + tree[childNum].weight, s);
    }
}

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    createBiTree(n, m);
    path[0] = 0;
    DFS(0, 1, tree[0].weight, s);
    return 0;
}