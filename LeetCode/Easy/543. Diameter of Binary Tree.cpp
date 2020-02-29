#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int depth(TreeNode* root, int& nodes) {
        if (!root) return 0;
        int leftDepth = depth(root->left, nodes);
        int rightDepth = depth(root->right, nodes);
        nodes = max(nodes, leftDepth + rightDepth + 1);
        return max(leftDepth, rightDepth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int nodes = 1;
        depth(root, nodes);
        return nodes - 1;
    }
};