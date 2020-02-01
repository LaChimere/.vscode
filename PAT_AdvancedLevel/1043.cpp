#include <iostream>
#include <vector>
using namespace std;

typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

void insertTree(BiTree &root, const int &x) {
    if (root == NULL) {
        root = new BiNode;
        root->data = x;
        root->lchild = root->rchild = NULL;
        return;
    }
    if (x < root->data)
        insertTree(root->lchild, x);
    else
        insertTree(root->rchild, x);
}

BiTree createTree(const vector<int> &seq) {
    BiTree root = NULL;
    for (int i = 0; i < seq.size(); i++)
        insertTree(root, seq[i]);
    return root;
}

vector<int> preOrder;
void getPreOrder(const BiTree &root) {
    if (root == NULL) return;
    preOrder.push_back(root->data);
    getPreOrder(root->lchild);
    getPreOrder(root->rchild);
}
vector<int> mirrorPreOrder;
void getMirrorPreOrder(const BiTree &root) {
    if (root == NULL) return;
    mirrorPreOrder.push_back(root->data);
    getMirrorPreOrder(root->rchild);
    getMirrorPreOrder(root->lchild);
}
vector<int> postOrder;
void getPostOrder(const BiTree &root) {
    if (root == NULL) return;
    getPostOrder(root->lchild);
    getPostOrder(root->rchild);
    postOrder.push_back(root->data);
}
vector<int> mirrorPostOrder;
void getMirrorPostOrder(const BiTree &root) {
    if (root == NULL) return;
    getMirrorPostOrder(root->rchild);
    getMirrorPostOrder(root->lchild);
    mirrorPostOrder.push_back(root->data);
}

int main() {
    int n, x;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        nums.push_back(x);
    }
    BiTree tree = createTree(nums);
    getPreOrder(tree);
    getMirrorPreOrder(tree);
    if (nums == preOrder) {
        printf("YES\n");
        getPostOrder(tree);
        for (int i = 0; i < n; i++) {
            printf("%d", postOrder[i]);
            if (i != n - 1)
                printf(" ");
        }
    } else if (nums == mirrorPreOrder) {
        printf("YES\n");
        getMirrorPostOrder(tree);
        for (int i = 0; i < n; i++) {
            printf("%d", mirrorPostOrder[i]);
            if (i != n - 1)
                printf(" ");
        }
    } else printf("NO");
    return 0;
}