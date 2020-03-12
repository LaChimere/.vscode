#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->right)
            return isUnivalTree(root->left) && isUnivalTree(root->right)
                && root->val == root->left->val && root->val == root->right->val;
        if (root->left) return isUnivalTree(root->left) && root->val == root->left->val;
        if (root->right) return isUnivalTree(root->right) && root->val == root->right->val;
        return true;
    }
};