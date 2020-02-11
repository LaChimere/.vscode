#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        return true;
    }
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return max(left_height, right_height) + 1;
    }
};