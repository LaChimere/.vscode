#include "tools"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inOrder(TreeNode* root, TreeNode*& pre, int& res) {
        if (!root) return;
        inOrder(root->left, pre, res);
        if (pre) res = min(res, root->val - pre->val);
        pre = root;
        inOrder(root->right, pre, res);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* pre = nullptr;
        inOrder(root, pre, res);
        return res;
    }
};