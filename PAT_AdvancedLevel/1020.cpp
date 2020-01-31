#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct BiNode {
    int key;
    BiNode *lchild;
    BiNode *rchild;
} BiNode, *BiTree;

vector<int> postOrder;
vector<int> inOrder;

BiTree createBiTree(int postL, int postR, int inL, int inR) {
    if (postL > postR)
        return NULL;
    BiNode *node = new BiNode;
    node->key = postOrder[postR];
    int k;
    for (k = inL; k <= inR; k++)
        if (inOrder[k] == postOrder[postR])
            break;
    int numLeft = k - inL;
    node->lchild = createBiTree(postL, postL + numLeft - 1, inL, k - 1);
    node->rchild = createBiTree(postL + numLeft, postR - 1, k + 1, inR);
    return node;
}

vector<int> layerOrder(const BiTree root) {
    vector<int> layer;
    queue<BiNode *> tree;
    tree.push(root);
    while (!tree.empty()) {
        BiNode *node = tree.front();
        tree.pop();
        layer.push_back(node->key);
        if (node->lchild != NULL) tree.push(node->lchild);
        if (node->rchild != NULL) tree.push(node->rchild);
    }
    return layer;
}

int main() {
    int n;
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        postOrder.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        inOrder.push_back(temp);
    }
    BiTree root = createBiTree(0, n - 1, 0, n - 1);
    vector<int> v(layerOrder(root));
    for (int i = 0; i < v.size(); i++) {
        printf("%d", v[i]);
        if (i < v.size() - 1) printf(" ");
    }
    return 0;
}