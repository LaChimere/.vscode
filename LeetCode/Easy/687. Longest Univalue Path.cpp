#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int arrowLength(TreeNode* root, int& path) {
        // 与第543题一起复习
        if (!root) return 0;
        int leftPath = arrowLength(root->left, path);
        int rightPath = arrowLength(root->right, path);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val)
            arrowLeft = leftPath + 1;
        if (root->right && root->right->val == root->val)
            arrowRight = rightPath + 1;
        path = max(path, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int path = 0;
        arrowLength(root, path);
        return path;
    }
};