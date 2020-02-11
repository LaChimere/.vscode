#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        if (root1->val != root2->val) return false;
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    //     bool isSymmetric(TreeNode* root) {
    //         turnTree(turnedRoot, root);
    //         return isSameTree(turnedRoot, root);
    //     }

    //     void turnTree(TreeNode* &root1, TreeNode* root2) {
    //         if (root2 == NULL) return;
    //         root1 = new TreeNode(root2->val);
    //         turnTree(root1->left, root2->right);
    //         turnTree(root1->right, root2->left);
    //     }

    //     bool isSameTree(TreeNode* p, TreeNode* q) {
    //         if (p == NULL && q == NULL) return true;
    //         if (p == NULL || q == NULL) return false;
    //         if (p->val != q->val) return false;
    //         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    //     }
    // private:
    //     TreeNode* turnedRoot = NULL;
};