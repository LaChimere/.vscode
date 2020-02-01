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

void getPre(const BiTree &root, vector<int> &vec) {
    if (root == NULL) return;
    vec.push_back(root->data);
    getPre(root->lchild, vec);
    getPre(root->rchild, vec);
}
vector<int> getPreOrder(const BiTree &root) {
    vector<int> vec;
    getPre(root, vec);
    return vec;
}

void getMirrorPre(const BiTree &root, vector<int> &vec) {
    if (root == NULL) return;
    vec.push_back(root->data);
    getMirrorPre(root->rchild, vec);
    getMirrorPre(root->lchild, vec);
}
vector<int> getMirrorPreOrder(const BiTree &root) {
    vector<int> vec;
    getMirrorPre(root, vec);
    return vec;
}

void getPost(const BiTree &root, vector<int> &vec) {
    if (root == NULL) return;
    getPost(root->lchild, vec);
    getPost(root->rchild, vec);
    vec.push_back(root->data);
}
vector<int> getPostOrder(const BiTree &root) {
    vector<int> vec;
    getPost(root, vec);
    return vec;
}

void getMirrorPost(const BiTree &root, vector<int> &vec) {
    if (root == NULL) return;
    getMirrorPost(root->rchild, vec);
    getMirrorPost(root->lchild, vec);
    vec.push_back(root->data);
}
vector<int> getMirrorPostOrder(const BiTree &root) {
    vector<int> vec;
    getMirrorPost(root, vec);
    return vec;
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
    vector<int> preOrder = getPreOrder(tree);
    vector<int> mirrorPreOrder = getMirrorPreOrder(tree);
    if (nums == preOrder) {
        printf("YES\n");
        vector<int> postOrder = getPostOrder(tree);
        for (int i = 0; i < n; i++) {
            printf("%d", postOrder[i]);
            if (i != n - 1)
                printf(" ");
        }
    } else if (nums == mirrorPreOrder) {
        printf("YES\n");
        vector<int> mirrorPostOrder = getMirrorPostOrder(tree);
        for (int i = 0; i < n; i++) {
            printf("%d", mirrorPostOrder[i]);
            if (i != n - 1)
                printf(" ");
        }
    } else printf("NO");
    return 0;
}