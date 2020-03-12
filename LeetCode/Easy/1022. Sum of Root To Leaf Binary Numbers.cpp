#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void preOrder(TreeNode* root, int cur, int& sum) {
        if (!root) return;
        cur = (cur << 1) + root->val;
        if (!root->left && !root->right) sum += cur;
        preOrder(root->left, cur, sum);
        preOrder(root->right, cur, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, cur = 0;
        preOrder(root, cur, sum);
        return sum;
    }
};